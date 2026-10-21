# 開發

正式入口為 `build.cmd`，會編譯全部原生角色流程與 GUI。`build.cmd native` 僅編譯核心，`build.cmd gui` 僅編譯 GUI。

現行流程檔位於 `src/official/generated`，來源清單為 SOURCES.json。角色方法保留官方原名與來源行號，請同時核對角色原文及 BaseChar。

開發用來源轉換：`python scripts/official_transpile.py`。未知語法會造成失敗。

現行離線檢查：`powershell -File scripts/build-official.ps1 -Test`。官方 Python 對照工具需要來源 requirements.txt 所列的 NumPy／OpenCV；不會向遊戲送出輸入。`scripts/verify_official_comparison.py` 核對原始 JSONL、角色狀態、方法涵蓋與來源雜湊。

v0.3.0 之前的靜態測試與歷史報告屬於當時版本，現行結果以 `evidence/official-comparison-20261021.json` 為準。實戰紀錄需保留版本、開始時間、隊伍與完整錯誤前後文。
