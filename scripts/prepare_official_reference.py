"""Restore the bundled source-text reference for offline developer comparisons."""
from pathlib import Path
import shutil
ROOT=Path(__file__).resolve().parent.parent
COMMIT='0b37b5b79e771297536ff1155db1c23131297558'
def prepare():
    reference=ROOT/'source_reference/upstream/master-0b37b5b'
    snapshot=ROOT/'.cache/official-0b37b5b'
    for path in reference.rglob('*'):
        if not path.is_file():continue
        relative=path.relative_to(reference)
        if path.name.endswith('.py.txt'):relative=relative.with_name(relative.name[:-4])
        target=snapshot/relative;target.parent.mkdir(parents=True,exist_ok=True)
        if not target.exists() or target.read_bytes()!=path.read_bytes():shutil.copyfile(path,target)
    return snapshot
if __name__=='__main__':print(prepare())
