---
title: 文本嵌入
categories: agi
tags: embedding
date: 2023-08-28
---

把文本转换为向量，用于向量检索，相似度计算

## M3E

- [m3e-base](https://huggingface.co/moka-ai/m3e-base)

M3E 是 Moka Massive Mixed Embedding 的缩写

- Moka，此模型由 MokaAI 训练，开源和评测，训练脚本使用 uniem ，评测 BenchMark 使用 MTEB-zh
- Massive，此模型通过千万级 (2200w+) 的中文句对数据集进行训练
- Mixed，此模型支持中英双语的同质文本相似度计算，异质文本检索等功能，未来还会支持代码检索
- Embedding，此模型是文本嵌入模型，可以将自然语言转换成稠密的向量

**<font color='Tomato'>模型对比</font>**

|                | 参数数量 | 维度 | 中文 | 英文 | s2s | s2p | s2c | 开源 | 兼容性 | s2s Acc | s2p ndcg@10 |
| :------------- | :------- | :--- | :--- | :--- | :-- | :-- | :-- | :--- | :----- | :------ | :---------- |
| m3e-small      | 24M      | 512  | 是   | 否   | 是  | 否  | 否  | 是   | 优     | 0.5834  | 0.7262      |
| m3e-base       | 110M     | 768  | 是   | 是   | 是  | 是  | 否  | 是   | 优     | 0.6157  | 0.8004      |
| text2vec       | 110M     | 768  | 是   | 否   | 是  | 否  | 否  | 是   | 优     | 0.5755  | 0.6346      |
| openai-ada-002 | 未知     | 1536 | 是   | 是   | 是  | 是  | 是  | 否   | 优     | 0.5956  | 0.7786      |

## uniem

- [github code](https://github.com/wangyuxinwhy/uniem)

