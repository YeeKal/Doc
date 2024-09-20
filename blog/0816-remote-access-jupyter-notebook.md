---
title: 一行令名开启 Jupyter Notebook 的远程访问
categories: 
tags: 
is_draft: true
date: 2024-08-16
keywords: 
cover: 
description: 
---

```bash
jupyter notebook --port 8060 --ip 0.0.0.0 --allow-root --NotebookApp.password='' --NotebookApp.token='1225' ../script/
```

这是一行命令开启远程访问的写法，会更加简洁，请指出该方法比之前需要配置的方法的优势，以及解释每一个参数的含义

你提供的命令 `jupyter notebook --port 8060 --ip 0.0.0.0 --allow-root --NotebookApp.password='' --NotebookApp.token='' ../script/` 确实可以快速开启 Jupyter Notebook 的远程访问，但是 **非常不安全**。让我们来逐一分析每个参数和潜在风险：

**参数解释:**

* `--port 8060`: 指定 Jupyter Notebook 运行的端口号为 8060。
* `--ip 0.0.0.0`: 监听所有可用的网络接口，这意味着任何设备只要知道你的 IP 地址，都可以访问你的 Jupyter Notebook。
* `--allow-root`: 允许 Jupyter Notebook 以 root 用户身份运行，这在大多数情况下是极其危险的。
* `--NotebookApp.password=''`: **禁用密码验证**，任何人都可以直接访问你的 Jupyter Notebook。
* `--NotebookApp.token=''`: **禁用 token 验证**，任何人都可以直接访问你的 Jupyter Notebook。
* `../script/`: 指定启动 Jupyter Notebook 的工作目录。

**优势：**

* **简单快捷:** 仅需一行命令即可启动 Jupyter Notebook 并开放远程访问。

**风险：**

* **极度不安全:**
* `--NotebookApp.password=''` 和 `--NotebookApp.token=''` 禁用了所有身份验证，任何人都可以无需密码直接访问你的 Jupyter Notebook，控制你的电脑，窃取数据。
* `--ip 0.0.0.0` 允许任何设备访问，增加了风险。
* `--allow-root` 以 root 身份运行 Jupyter Notebook，一旦被入侵，攻击者将获得最高权限，后果不堪设想。

**建议：**

**永远不要在生产环境或任何他人可以访问的网络中使用以上命令启动 Jupyter Notebook！**

为了安全地进行远程访问，请参考以下步骤：

1. **生成配置文件：** 运行 `jupyter notebook --generate-config` 生成配置文件。
2. **设置密码：**
* 打开生成的配置文件 `~/.jupyter/jupyter_notebook_config.py` 。
* 找到 `c.NotebookApp.password` ，取消注释，并使用 `jupyter notebook password` 命令生成安全的密码哈希值并填入。
3. **设置 Token：**
* 找到 `c.NotebookApp.token` ，取消注释，并设置一个强随机字符串作为 token。
4. **绑定特定 IP：**
* 找到 `c.NotebookApp.ip` ，取消注释，并将其设置为你的本地 IP 地址（例如 `192.168.1.100` ），限制只能从你的电脑访问。
5. **禁用 root 权限：**
* 不要使用 `--allow-root` 参数，确保 Jupyter Notebook 不以 root 用户身份运行。

**安全的启动命令示例:**

```bash
jupyter notebook --config ~/.jupyter/jupyter_notebook_config.py
```

请务必重视安全问题，避免使用任何可能导致安全漏洞的配置。