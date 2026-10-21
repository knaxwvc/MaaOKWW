"""Return the newest project include timestamp for each native translation unit."""
import json
import pathlib
import re
import sys
ROOT=pathlib.Path(__file__).resolve().parent.parent
INCLUDES=[ROOT/'src',ROOT/'sdk/include']
memo={}
def newest(path,visiting=None):
    path=path.resolve()
    if path in memo:return memo[path]
    visiting=set() if visiting is None else visiting
    if path in visiting:return 0
    visiting=visiting|{path};stamp=path.stat().st_mtime
    for name in re.findall(r'^\s*#include\s*"([^"]+)"',path.read_text(encoding='utf-8-sig'),re.M):
        for candidate in [path.parent/name]+[folder/name for folder in INCLUDES]:
            if candidate.is_file():stamp=max(stamp,newest(candidate,visiting));break
    memo[path]=stamp
    return stamp
sources=list((ROOT/'src/official/generated').glob('*.cpp'))+[ROOT/'src/official/OfficialCharacter.cpp',ROOT/'src/official/OfficialTask.cpp',ROOT/'src/main.cpp',ROOT/'src/tests/official_roles_test.cpp']
print(json.dumps({str(path):newest(path) for path in sources}))
