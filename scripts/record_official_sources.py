"""Record the pinned source bytes and native method coverage for a release."""
import ast
import hashlib
import json
import pathlib
import re
import shutil
ROOT=pathlib.Path(__file__).resolve().parent.parent
COMMIT='0b37b5b79e771297536ff1155db1c23131297558'
SNAPSHOT=ROOT/'.cache/official-0b37b5b'
REFERENCE=ROOT/'source_reference/upstream/master-0b37b5b'
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    previous=json.loads((ROOT/'SOURCES.json').read_text(encoding='utf-8-sig'))
    for path in (SNAPSHOT/'src').rglob('*.py'):
        target=REFERENCE/path.relative_to(SNAPSHOT);target=target.with_name(target.name+'.txt');target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(path,target)
    for name in ('config.py','requirements.txt','assets/coco_annotations.json'):
        target=REFERENCE/name
        if target.suffix=='.py':target=target.with_name(target.name+'.txt')
        target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(SNAPSHOT/name,target)
    coverage=json.loads((ROOT/'.cache/official-translation-coverage.json').read_text(encoding='utf-8'))
    records={entry['character']:entry for entry in coverage['files']}
    rows=[]
    for old in previous['characters']:
        name=old['character'];cpp=ROOT/'src/official/generated'/f'{name}.cpp';source=SNAPSHOT/'src/char'/f'{name}.py';ref=REFERENCE/'src/char'/f'{name}.py.txt'
        rows.append(dict(character=name,native_file=cpp.relative_to(ROOT).as_posix(),header_file=old.get('header_file',old['native_file']),native_sha256=sha(cpp),source_kind='github',source=f'https://github.com/ok-oldking/ok-wuthering-waves/blob/{COMMIT}/src/char/{name}.py',sha256=sha(source),reference=ref.relative_to(ROOT).as_posix(),official_methods=len(records[name]['methods']),official_statements=records[name]['statement_count'],previous_origin=old.get('previous_origin'),previous_official_source={key:old[key] for key in ('source','sha256','reference')}))
    common=[]
    for name in ('src/char/BaseChar.py','src/char/CharFactory.py','src/Labels.py','src/task/BaseCombatTask.py','src/task/BaseWWTask.py','src/task/AutoCombatTask.py','src/combat/CombatCheck.py'):
        common.append(dict(source=f'https://github.com/ok-oldking/ok-wuthering-waves/blob/{COMMIT}/{name}',reference=(REFERENCE/(name+'.txt')).relative_to(ROOT).as_posix(),sha256=sha(SNAPSHOT/name)))
    result=dict(version='20261021-okww-official-all52-30',gui_build='20261021-gui-official-all52-30',upstream_ref='master',upstream_release='master',upstream_commit=COMMIT,source_checked_on='2026-10-21',local_root=previous['local_root'],characters=rows,common=common,translation=dict(runtime='native C++17; no Python interpreter',role_classes=52,role_methods=sum(row['official_methods'] for row in rows),base_methods=len(records['BaseChar']['methods']),unmapped_ast=coverage['errors'],coverage='evidence/official-translation-coverage-20261021.json',task_coverage='evidence/official-task-coverage-20261021.json'),historical_manifest='source_reference/history/SOURCES-before-v030.json')
    history=ROOT/result['historical_manifest'];history.parent.mkdir(parents=True,exist_ok=True)
    if not history.exists():history.write_text(json.dumps(previous,ensure_ascii=False,indent=2),encoding='utf-8')
    (ROOT/'SOURCES.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    lines=['# 戰鬥原碼來源','',f'固定官方提交：[{COMMIT}](https://github.com/ok-oldking/ok-wuthering-waves/tree/{COMMIT})。','', '52 名角色及 BaseChar 全部以此提交轉寫。每個方法保留原名、條件、迴圈、回呼、時間參數與來源行號；執行時使用原生 C++。','', '|角色|C++ 流程檔|官方來源|方法數|','|---|---|---|---|']
    for row in rows:lines.append(f'|{row["character"]}|{row["native_file"]}|[原碼]({row["source"]})|{row["official_methods"]}|')
    lines+=['','完整原文副本在 `source_reference/upstream/master-0b37b5b`。舊本地來源、舊版提交與 v0.2.3 清單保留於歷史資料，現行來源以本頁及 SOURCES.json 為準。','']
    (ROOT/'SOURCES.md').write_text('\n'.join(lines),encoding='utf-8')
    shutil.copyfile(ROOT/'.cache/official-translation-coverage.json',ROOT/'evidence/official-translation-coverage-20261021.json')
    shutil.copyfile(ROOT/'.cache/official-task-translation-coverage.json',ROOT/'evidence/official-task-coverage-20261021.json')
    print('recorded',len(rows),'roles',result['translation']['role_methods'],'role methods',result['translation']['base_methods'],'base methods')
if __name__=='__main__':main()
