# MaaOKWW v0.3.0 — 52 名角色官方流程移植

## 下載與使用

下載 `MaaOKWW-v0.3.0-win-x64.zip`，完整解壓後執行 `啟動戰鬥.bat`。F10 開始／暫停，F11 停止。公開包採用預設設定；升級前請保留舊版資料。

## 本版更新

- 執行主體為 C++17／MaaFramework v5.14.0，執行 BOT 不需要 Python。
- 全部 52 名角色依 OK-WW master 固定提交 `0b37b5b79e771297536ff1155db1c23131297558` 重新轉寫。
- 包含 412 個角色方法、88 個 BaseChar 方法及 15 個共用任務方法；保留官方條件、時間參數、回呼、狀態與來源行號。
- 納入官方停止／重啟清理、等待旗標還原及換人流程；一／二／三人隊伍自動辨識，保留三連點與長按時序。
- 每名角色有獨立、可修改的完整 C++ 流程；附固定原文、逐檔 SHA256、SDK、286 份辨識模板、本地 OCR 模型與授權。
- 更新原生 GUI、戰鬥紀錄顯示、背景輸入及技能辨識接口。

## 證據與狀態

184 組受控離線對照相同：156 組角色流程、10 組單人／雙人流程、18 組影像計算。角色流程包括 149 組正常結束、5 組與官方一致的中斷及 2 組與官方一致的操作上限中止。另有 5 組等待旗標檢查通過，286 份模板像素相同。

**`live_combat_verified=false`**：尚未取得 v0.3.0 實戰驗收紀錄，因此標記為預發行。沒有宣稱全部實戰技能狀態均已驗證。

來源：[SOURCES.md](https://github.com/knaxwvc/MaaOKWW/blob/main/SOURCES.md)；詳細證據：[移植紀錄](https://github.com/knaxwvc/MaaOKWW/blob/main/docs/OFFICIAL_ALL52_20261021.md)。

## 上游與授權

感謝 [OK-WW](https://github.com/ok-oldking/ok-wuthering-waves) 與 [MaaFramework](https://github.com/MaaXYZ/MaaFramework)。本專案為獨立移植版本，非上游官方發行；依 AGPL-3.0 發布並附各第三方元件授權。公開包不含私人設定、個人校準、私人 LOG 或遊戲截圖。
