# 上游與第三方來源

| 部分 | 來源 | 隨附授權 |
|---|---|---|
| 戰鬥手法與原始辨識資料 | [OK-WW](https://github.com/ok-oldking/ok-wuthering-waves) 及 SOURCES.json 列出的本地檔案 | LICENSE、licenses/OK-WW-AGPL-3.0.txt |
| 原生自動化框架與 SDK | [MaaFramework](https://github.com/MaaXYZ/MaaFramework)，執行庫 v5.14.0 | licenses/MaaFramework-LGPL-3.0.md |
| 第三方執行 DLL | 官方 MaaFramework Windows 發行內容；目前成品的 DLL 保持原樣 | 發行內容中的授權／notice，隨執行庫安裝保存 |
| OCR 模型 | 本地 OK-WW 移植成品使用的 Maa OCR 模型 | 保留模型原檔；MaaFramework 使用的 OCR 來源見其上游說明 |

現行 52 名角色及共用戰鬥來源固定為官方 master `0b37b5b79e771297536ff1155db1c23131297558`，原文、逐檔 SHA256 與 C++ 對應見 SOURCES.json。歷史來源副本保留。

原始檔中的署名、來源註解及授權文字保留。此專案為獨立移植版本。

## 原生數值元件

- PocketFFT：固定提交 `33ae5dc94c9cdc7f1c78346504a85de87cadaa12`，來源為 NumPy v2.5.2 使用的 PocketFFT 子模組；完整 BSD 授權見 `licenses/PocketFFT-BSD-3-Clause.txt`，原始標頭保留署名。
- NumPy v2.5.2：單精度加總順序依其 `numpy/_core/src/umath/loops_utils.h.src` 實作；BSD 授權見 `licenses/NumPy-BSD-3-Clause.txt`。

上述元件以 C++ 編譯，沒有隨 BOT 執行 Python 解譯器。
