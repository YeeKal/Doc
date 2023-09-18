---
title: tmux tutorial
categories: linux
tags: linux
date: 2023-03-07
---

## tmux

```python
tmux ls # list session
tmux detach # session 与当前窗口分离（所谓分离就是隐藏了会话，窗口恢复到原来）
tmux attach -t <n> # 重新接入会话
tmux switch -t <n> # 切换会话
tmux new-window     # 新建窗口, 而多个窗口依然属于同一个会话

# shortcut
d   # detach
s   # list

# split pane 分割窗格
%   #左右
“   # 上下
;   # 切换到上一个
o   # 切换到下一个

Ctrl+b p：切换到上一个窗口（按照状态栏上的顺序）。
Ctrl+b n：切换到下一个窗口。
Ctrl+b 0-9：切换到下第几个窗口
ctrl+b c: new window
ctrl+b x: 关闭分屏
```
## 

```yaml
# ~/.tmux.conf
set -g mouse on

set -g default-terminal "screen-256color"
unbind '"'
bind - splitw -v
unbind %
bind | splitw -h

#witch panes using Shift-arrow without prefix
bind -n S-Left select-pane -L
bind -n S-Right select-pane -R
bind -n S-Up select-pane -U
bind -n S-Down select-pane -D

# switch windows using Alt-arrow without prefix
bind -n M-Left previous-window
bind -n M-Right next-window

```