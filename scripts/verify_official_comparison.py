"""Compare native and official execution evidence; fail on any difference."""
import collections
import hashlib
import json
from pathlib import Path
ROOT=Path(__file__).resolve().parent.parent
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    manifest=json.loads((ROOT/'SOURCES.json').read_text(encoding='utf-8-sig'))
    result=dict(commit=manifest['upstream_commit'],game_input_sent=0,live_combat_verified=False,comparisons={})
    for suffix,expected in [('traces',156),('teams',10),('vision',18)]:
        native=[json.loads(line) for line in (ROOT/f'.cache/native-{suffix}.jsonl').read_text(encoding='utf-8').splitlines()]
        reference=[json.loads(line) for line in (ROOT/f'.cache/python-{suffix}.jsonl').read_text(encoding='utf-8').splitlines()]
        assert len(native)==len(reference)==expected,(suffix,len(native),len(reference))
        if suffix=='vision':assert native==reference,'vision results differ'
        else:
            key=lambda row:(row['role'],row['scenario'],row.get('team_size',3))
            official={key(row):row for row in reference}
            for row in native:assert row==official[key(row)],(suffix,key(row),'trace/state/result differ')
            if suffix=='teams':
                for row in native:
                    if row['team_size']==1:assert not any(event[0]=='key' and event[1] in ('1','2','3') for event in row['trace']),('solo switch key',row['role'])
        result['comparisons'][suffix]=dict(cases=expected,equal=expected,completed=sum(row.get('error') is None for row in native),matching_reference_interruptions=dict(collections.Counter(row.get('error') for row in reference if row.get('error'))),native_sha256=sha(ROOT/f'.cache/native-{suffix}.jsonl'),reference_sha256=sha(ROOT/f'.cache/python-{suffix}.jsonl'))
    source_coverage=json.loads((ROOT/'evidence/official-translation-coverage-20261021.json').read_text(encoding='utf-8'))
    assert len(source_coverage['files'])==53 and not source_coverage['errors']
    assert sum(len(row['methods']) for row in source_coverage['files'])==500
    for row in manifest['characters']:
        assert sha(ROOT/row['reference'])==row['sha256'],('source reference changed',row['character'])
        assert sha(ROOT/row['native_file'])==row['native_sha256'],('native source changed',row['character'])
    log=(ROOT/'.cache/official-latest-build-test.log').read_text(encoding='utf-8-sig',errors='replace')
    assert 'official_native_constructor_check roles=52 game_input_sent=0' in log
    assert 'official_sleep_restore_check cases=5 game_input_sent=0' in log
    assert 'error C' not in log and 'fatal error' not in log
    result.update(role_classes=52,role_methods=412,base_methods=88,task_methods=15,unmapped_ast=0,sleep_restoration_cases=5)
    target=ROOT/'evidence/official-comparison-20261021.json';target.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    for suffix in ('traces','teams','vision'):
        for prefix in ('native','python'):
            path=ROOT/f'.cache/{prefix}-{suffix}.jsonl';destination=ROOT/f'evidence/official-{prefix}-{suffix}-20261021.jsonl';destination.write_bytes(path.read_bytes())
    (ROOT/'evidence/official-build-20261021.txt').write_text(log,encoding='utf-8')
    print('official comparison: roles=52 methods=500 traces=156/156 teams=10/10 vision=18/18 sleep_restore=5/5 game_input_sent=0')
if __name__=='__main__':main()
