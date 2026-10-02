# MaaOKWW

[![Windows build](https://github.com/knaxwvc/MaaOKWW/actions/workflows/windows.yml/badge.svg)](https://github.com/knaxwvc/MaaOKWW/actions/workflows/windows.yml)
[![License: AGPL-3.0](https://img.shields.io/badge/License-AGPL--3.0-blue.svg)](LICENSE)
![Platform](https://img.shields.io/badge/Platform-Windows%20x64-blue)

以 **C++ 與 MaaFramework** 為執行核心的鳴潮戰鬥 BOT。角色手法移植自 OK-WW，涵蓋目標與血條監看、鎖定、技能、普通攻擊、重擊、協奏及切人。

## 角色與來源

共 **51 名角色**，每名保留獨立、可修改的 C++ 手法檔：

- **50 名既有角色**：來自 `C:\ok-ww222\data\apps\ok-ww\working\src\char` 本地原碼。
- **心（Hsin）**：來自 [OK-WW 的 Hsin.py](https://github.com/ok-oldking/ok-wuthering-waves/blob/36c557437de745cdef506bcfa148569d3e09cfcf/src/char/Hsin.py)，固定 commit `36c557437de745cdef506bcfa148569d3e09cfcf`。

[SOURCES.md](SOURCES.md) 列出全部角色與手法對應；[SOURCES.json](SOURCES.json) 記錄原始檔 SHA256。各角色檔開頭也保留來源。`source_reference/*.py.txt` 是原碼對照副本；執行 BOT 不使用 Python。

## 下載與使用

1. 從 [Releases](https://github.com/knaxwvc/MaaOKWW/releases) 下載 `MaaOKWW-v0.1.0-win-x64.zip` 並完整解壓。
2. 自行開啟鳴潮。
3. 雙擊 `啟動戰鬥.bat`，接受 Windows 權限提示。
4. 選擇自動辨識隊伍，確認技能鍵，按「開始」。

**F10** 開始／停止，**F11** 停止。設定保存於 `config.ini`，戰鬥紀錄保存於 `native_run.log`。核心以 MaaFramework 的 Win32 背景截圖與輸入持續監看戰鬥。

## 從原碼編譯

需求：Windows x64、Git、Visual Studio 2022（含「使用 C++ 的桌面開發」或對應 Build Tools）。

```powershell
git clone https://github.com/knaxwvc/MaaOKWW.git
cd MaaOKWW
powershell -NoProfile -File scripts/setup-runtime.ps1
.\build.cmd
Copy-Item config.example.ini config.ini
.\啟動戰鬥.bat
```

執行庫固定為官方 **MaaFramework v5.14.0**，安裝腳本先核對發行 ZIP 的 SHA256，再提取 DLL。原始辨識圖、OCR 模型、SDK 標頭與 Pipeline 隨原碼保留。

`build.cmd native` 只編譯核心。`scripts/package.ps1` 可將編譯結果、執行庫、辨識資源與對應原碼打包成 Windows ZIP。GitHub Actions 會執行 Windows 編譯並提供打包下載。

## 專案結構

| 路徑 | 用途 |
|---|---|
| `src/char/` | 每名角色的手法、狀態與切人優先序 |
| `src/char/OriginalBaseChar.h` | 共用技能、重擊、等待、普通點擊 |
| `src/task/BaseCombatTask.h` | 戰鬥監看、Maa 輸入、辨識與切人確認 |
| `src/combat/` | Maa 模板辨識／OCR，以及原碼的血條、協奏與能量判斷 |
| `resource/image/original/` | 286 張原始解析度模板；本地 281 張、心 5 張 |
| `resource/pipeline/` | Maa Pipeline 節點及辨識設定 |
| `resource/model/` | 離線 OCR 模型 |
| `source_reference/` | 50 名本地角色與心的原始手法副本 |
| `scripts/` | 執行庫安裝與發行打包 |

更多修改說明見 [架構文件](docs/ARCHITECTURE.md) 與 [CONTRIBUTING.md](CONTRIBUTING.md)。

## 目前狀態

目前完成 Windows 原生編譯、來源完整性檢查及必要離線辨識。本次 51 名角色版本尚未取得新版遊戲實戰紀錄。詳見 [驗證範圍](docs/VALIDATION.md)；實際問題可透過 [Issues](https://github.com/knaxwvc/MaaOKWW/issues) 回報。

## 授權與上游

本專案保留 OK-WW 的 [AGPL-3.0](LICENSE) 授權與 MaaFramework 的 LGPL-3.0 授權；授權文字保存於 `licenses/`。上游與第三方來源見 [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md)。

- [OK-WW](https://github.com/ok-oldking/ok-wuthering-waves)
- [MaaFramework](https://github.com/MaaXYZ/MaaFramework)
