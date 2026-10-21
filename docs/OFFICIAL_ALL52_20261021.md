# 全角色官方流程移植 — v0.3.0

## 原碼基準與範圍

2026-10-21 透過官方 Git 遠端確認 master 為 `0b37b5b79e771297536ff1155db1c23131297558`。

|項目|數量／位置|
|---|---|
|角色|52 名，全部重新轉寫|
|角色方法|412 個|
|共用 BaseChar 方法|88 個|
|官方換人與隊友解放圖示方法|15 個|
|辨識原圖|286 份，逐像素相同|
|語法未轉換項目|0|
|執行主體|C++17、MaaFramework v5.14.0|

各角色的方法、條件、迴圈、時間參數、回呼及狀態欄位依官方原文產生 C++。包含 BaseChar 的 E／Q／R 等待流程、長按、連續普攻、協奏、Buff、角色專屬頻譜／條紋／遮罩與跨角色條件。角色註冊次序、定位、屬性、Buff 時間、模板別名一併對齊官方 CharFactory。

本次也納入官方 d590b6b 的更新：等待時以 finally 還原進入前的 skip_combat_check；離開隊伍／大世界時清空角色、冷卻及卡肉紀錄；停止例外向上傳遞。F10／F11 再啟動由新原生程序建立全新狀態。

## 原生檔案與修改方式

- `src/official/generated/角色名.cpp`：完整角色方法，每段有官方檔案與行號。`register_method` 的名稱對應原方法名。
- `src/official/generated/BaseChar.cpp`：共用戰鬥方法。
- `src/official/generated/BaseCombatTask.cpp`：官方換人選擇、執行、延奏回呼與隊友解放圖示。
- `src/official/OfficialTask.cpp`：Maa 截圖、模板查找、按鍵、冷卻與 ROI 接口。
- `src/official/OfficialValue.h`：值、Tuple 真值、參數綁定與回呼生命週期。
- `source_reference/upstream/master-0b37b5b`：固定提交的原文副本。
- `SOURCES.json`：52 名角色的原文、C++ 路徑與 SHA256。

執行檔沒有 Python 解譯器、Python DLL 或執行時 AST。各角色的 if／while／for 與方法回呼都編譯成 C++。`scripts/official_transpile.py` 僅供開發時由原文重新產生 C++；遇到未支援的語法會直接失敗。修改 C++ 後執行 `build.cmd` 即可編譯核心及 GUI，標準編譯入口不需要 Python。

保留 C:\ok-ww222 的三連點規則、單次輸入總時間與長按；一／二／三人隊伍自動辨識。單人隊伍由官方換人選擇器回傳目前角色，不發送 1／2／3 換人鍵。原有背景輸入、GPU 設定、校準資料與戰鬥紀錄顯示保留。

## 離線證據與界線

相同假畫面、時鐘、冷卻及輸入條件下，直接執行官方 Python 原文，再比對編譯後 C++ 的操作序列、參數、狀態及結束結果。

|核對|結果|
|---|---|
|52 名角色 × 3 組情境|156／156 一致|
|單人及雙人隊伍|10／10 一致，單人沒有換人鍵|
|條紋、頻譜、圓環遮罩|18／18 一致|
|等待中斷與巢狀等待旗標還原|5／5 通過|
|原始模板裁切像素|286／286 相同|

156 組情境中，149 組正常結束，5 組依官方流程在換人時遇到測試畫面 HUD 消失而中斷，2 組由測試器操作上限中止；兩端結果相同。上述紀錄不代表所有技能狀態均已實戰覆蓋。

NumPy v2.5.2 的單精度運算與 PocketFFT 提交已固定，相關授權隨包附上。Maa 的模板及 OCR 仍從遊戲畫面取得資料。

證據為 `evidence/official-comparison-20261021.json`、`official-assets-20261021.json` 及各組原始 JSONL。`live_combat_verified=false`：本版未啟動遊戲實戰，實際戰鬥由使用者驗收並提供 LOG。

## 公開發布

下載：[v0.3.0](https://github.com/knaxwvc/MaaOKWW/releases/tag/v0.3.0)。完整解壓後執行 `啟動戰鬥.bat`。公開包採用 `config.example.ini` 的預設設定。

公開包包含原生執行檔、Maa 執行庫、辨識資源、授權與對應原碼；不包含個人校準、私人戰鬥 LOG 或遊戲截圖。升級前請自行保留舊版目錄與設定。
