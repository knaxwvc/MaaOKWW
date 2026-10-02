# 修改與貢獻

角色手法以 SOURCES.md 的原碼為對照。修改時保留技能順序、辨識條件、等待時間與狀態更新的對應；若刻意改變手法，請在變更說明中寫清楚。

## 常用入口

- 修改角色：`src/char/<角色>.h`；切人優先序也在對應角色檔。
- 共用技能與等待：`src/char/OriginalBaseChar.h`。
- 戰鬥監看及切人確認：`src/task/BaseCombatTask.h`。
- 辨識圖片與 ROI：`resource/image/original`、`src/combat/OriginalBoxes.h`、`OriginalTemplates.h`。
- 新增角色時更新 `CharFactory.h`、`OriginalCharFactory.h`、Pipeline 與 SOURCES.md／SOURCES.json。

`source_reference` 保存來源的原始位元組，請勿因格式整理而修改。新增來源時記錄固定 commit 或對照原始檔雜湊。

## 編譯

先執行 `scripts/setup-runtime.ps1`，再執行 `build.cmd`。SDK 標頭隨原碼保存。完整編譯會輸出核心和 GUI；`build.cmd native` 僅輸出核心。

回報戰鬥問題時，提供角色隊伍、解析度、預期的原碼步驟、实际觀察及相關時間附近的紀錄。請明確區分離線檢查與遊戲實戰結果。
