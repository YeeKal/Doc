---
title: gradio
categories: python
tags: python
date: 2023-07-23
---

gradio: Build & Share Delightful Machine Learning Apps

快速部署模型推理前端

## A simple text2text demo

```python
import gradio as gr
def question_answer(context, question):
    return ("the answer is {}".format(question), 0.7)

gr.Interface(fn=question_answer, inputs=["text", "text"], outputs=["textbox", "text"]).launch()
```


![gradio_demo.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/python/imgs/gradio_demo.png)

## allow remote access in LAN

```python
demo.launch(server_name="0.0.0.0")   
# demo.launch(ssl_verify=False, share=False,debug=False,server_name="0.0.0.0")   
```
## ChatInterface

similar to gr.Interface, but is specifically designed for chatbot UIs

```Python
import random
import gradio as gr

def random_response(message, history):
    return random.choice(["Yes", "No"])

demo = gr.ChatInterface(random_response)

demo.launch()
```
![gradio_chatinterface.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/python/imgs/gradio_chatinterface.png)



## color block

![gradio_color_block.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/python/imgs/gradio_color_block.png)
