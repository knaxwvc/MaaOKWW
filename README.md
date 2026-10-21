# MaaOKWW

[![Windows build](https://github.com/knaxwvc/MaaOKWW/actions/workflows/windows.yml/badge.svg)](https://github.com/knaxwvc/MaaOKWW/actions/workflows/windows.yml)
[![License: AGPL-3.0](https://img.shields.io/badge/License-AGPL--3.0-blue.svg)](LICENSE)

鳴潮自動戰鬥工具，執行主體為 **C++／MaaFramework v5.14.0**。

v0.3.0 將 **52 名角色、412 個角色方法及 88 個 BaseChar 方法** 全部依官方 master `0b37b5b79e771297536ff1155db1c23131297558` 重新轉寫，並接入官方換人流程及最新的暫停／重啟清理。所有角色方法保留官方條件、手法、時間參數、迴圈、回呼與來源行號。

## 啟動

1. 從 [v0.3.0 發布頁](https://github.com/knaxwvc/MaaOKWW/releases/tag/v0.3.0) 下載 `MaaOKWW-v0.3.0-win-x64.zip` 並完整解壓。
2. 關閉舊版戰鬥視窗，雙擊 `啟動戰鬥.bat`。
3. 在遊戲中組隊，按 F10 開始／暫停，F11 停止。

自動辨識一／二／三人隊伍；單人可戰鬥，雙人與三人維持隊伍輪轉。輸入及截圖使用 Maa 的背景接口。

GUI 保留戰鬥設定、按鍵設定及戰鬥紀錄。「開啟角色原始碼」會開啟完整 C++ 流程資料夾。LOG 位於同資料夾 `native_run.log`，新版識別為 `20261021-okww-official-all52-30`。

## 原碼與編譯

- 每名角色完整流程：`src/official/generated/角色名.cpp`。
- 共用方法：`BaseChar.cpp`、`BaseCombatTask.cpp`。
- 固定來源、逐檔 SHA256 與方法數：[SOURCES.md](SOURCES.md)、`SOURCES.json`。
- 修改 C++ 後執行 `build.cmd`。需要 Visual Studio C++ Build Tools；標準編譯及執行不需要 Python。
- `scripts/official_transpile.py` 是開發用的原文轉換器；執行它會依隨附官方原文重新產生 C++，覆寫產生檔中的手動修改。

首次從 GitHub 原碼編譯與啟動：

```powershell
git clone https://github.com/knaxwvc/MaaOKWW.git
cd MaaOKWW
powershell -NoProfile -File scripts/setup-runtime.ps1
.\build.cmd
Copy-Item config.example.ini config.ini
.\啟動戰鬥.bat
```

執行庫安裝腳本固定 MaaFramework v5.14.0 並核對官方 ZIP 的 SHA256。詳細結構見 [架構](docs/ARCHITECTURE.md)，修改及離線對照方式見 [開發說明](CONTRIBUTING.md)。

## 本版核對

156 組角色流程、10 組單人／雙人流程及 18 組頻譜／遮罩結果，均與直接執行官方原文一致；5 組等待旗標還原檢查通過。286 份官方辨識圖片的裁切範圍及像素一致。完整範圍及中斷情境見 [移植紀錄](docs/OFFICIAL_ALL52_20261021.md)。

`live_combat_verified=false`：本版已編譯並完成離線對照，實戰由使用者驗收並提供 LOG。

## 授權

本專案依 [AGPL-3.0](LICENSE) 發布；[OK-WW](https://github.com/ok-oldking/ok-wuthering-waves) 原碼、[MaaFramework](https://github.com/MaaXYZ/MaaFramework) 與第三方元件的來源及授權見 [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) 及 `licenses/`。本工具為獨立移植版本，非 OK-WW 或 MaaFramework 官方發行。
