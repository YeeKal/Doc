---
title: Stable Diffusion
categories: 
tags: 
date: 2023-08-25
---

- [本地部署stable-diffusion-webui](https://sspai.com/post/79868)
- Lora
- ControlNet 
- [AUTOMATIC1111 stable-diffusion-webui](https://github.com/AUTOMATIC1111/stable-diffusion-webui)
- [提示词生成器](https://tag.redsex.cc/)
- [promptart: 提示词搜索](https://promptart.cc/)
- [civitai: models share](https://civitai.com/)
- [liblibai: 国内版 models share](https://www.liblibai.com/)
- [lexica: 提示词搜索](https://lexica.art/)
- [Stable Diffusion 基础到高阶教程](https://vocus.cc/neversaysd/home)

- [风格提示词](https://supagruen.github.io/StableDiffusion-CheatSheet/)
## SDXL model(Stable Diffusion XL)

SDXL: Improving Latent Diffusion Models for High-Resolution Image Synthesis

**<font color='Tomato'>Model Spec</font>**

- [arxiv](https://arxiv.org/abs/2307.01952)

|     |
| --- |
| ![SDXL SPEC](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/2023-08-25_15-18.png) |
|**Left:** Comparing user preferences between SDXL and Stable Diffusion 1.5 & 2.1. While SDXL already clearly outperforms Stable Diffusion 1.5 & 2.1, adding the additional refinement stage boosts performance. **Right:** Visualization of the two-stage pipeline: We generate initial latents of size 128 × 128 using SDXL. Afterwards, we utilize a specialized high-resolution refinement model and apply SDEdit [28] on the latents generated in the first step, using the same prompt. SDXL and the refinement model use the same autoencoder |


The SDXL model consists of two models — The base model and the refiner model. The language model (the module that understands your prompts) is a combination of the largest OpenClip model (ViT-G/14) and OpenAI’s proprietary CLIP ViT-L

- picture size: 1024 x 1024


**<font color='Tomato'>Usage on Colab</font>**

- [Colab PRACTICE: StableDiffusionXL_Text2Image](https://colab.research.google.com/drive/18ZwvrW6uOcJchFwEnOMIBCiTwmkPBMvG#scrollTo=bVWg9enGtdNt)
- [huggingface： diffusers code](https://github.com/huggingface/diffusers): A library that offers an implementation of various diffusion models, including text-to-image models.
- [huggingface： diffusers doc](https://huggingface.co/docs/diffusers/v0.20.0/en/api/pipelines/stable_diffusion/stable_diffusion_xl)
- [Stability-AI: generative-models](https://github.com/Stability-AI/generative-models)

```python
prompt = "cute robot stands on the moon, shallow depth of field, cinematic composition --ar 16:9"

start = datetime.now()
image = pipe(prompt=prompt).images[0]
print((datetime.now() - start).seconds)

display(image)
```

|prompt| demo1  | demo2  |
|---|---|---|
|cute robot stands on the moon, shallow depth of field, cinematic composition --ar 16:9| ![robot_stands_on_the_moon](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/download.png)  | ![robot_stands_on_the_moon](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/stable_diffusion_robot2.png)  |
|||
|The girl who is drawing. Makoto Shinkai style,Portrait,highly detailed, sharp focus,sci-fi, stunningly beautiful, dystopian, --ar 16:9|![alt](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/20230826123856.png)|![alt](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/20230826131728.png)|
||![alt](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/20230826132320.png)|![alt](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/20230826132320.png)|
|snoopy|![alt](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/20230827102254.png)|![alt](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/20230827102254.png)|


- ref links
    - [medium: how to run sdxl 1.0](https://medium.com/@andysingal/how-to-run-sdxl-1-0-model-629048e49e70)

防止超时断连

```js
function ConnectButton(){
    console.log("Connect pushed"); 
    document.querySelector("#top-toolbar > colab-connect-button").shadowRoot.querySelector("#connect").click() 
}
setInterval(ConnectButton,60000);

// id: the result outpur
// clearInterval(id);  // stop the execution
```

突破77token限制

## Stable diffusion webui on colab

- [stable-diffusion-webui-colab](https://github.com/camenduru/stable-diffusion-webui-colab)

## Stable Diffusion API

- [api reference](https://platform.stability.ai/docs/api-reference#tag/v1user)

## LoRA 微调

- [LoRA](https://github.com/microsoft/LoRA)
- [lora for fine-tuning diffusion model](https://github.com/cloneofsimo/lora)

Low-Rank Adaptation of Large Language Models

通过注入训练层对模型进行微调,由于没有直接改变大模型的权重.大大减少了训练计算量

|lora model|example|
|---|---|
|[KoreanDollLikeness_v10](https://huggingface.co/Kanbara/doll-likeness-series) 同系列：ChinaDollLikeness, JapaneseDollLikeness|![alt](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/20230827121527.png)|
|[cutegirlmix4](https://civitai.com/models/14171/cutegirlmix4)|![alt](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08xLtYSU7.png)|
|[Makoto Shinkai style LoRA](https://civitai.com/models/10626/makoto-shinkai-your-name-substyles-style-lora)|![alt](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/20230827122526.png)![alt](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/20230827122603.png)|


## 提示词

extremely detail

## style


> Neo-expressionism of a cartoonish pluto , in the style of pulled, scraped, and scratched, meditative, unconventional poses, spiky mounds, 1970s, twisted characters, soggy Banksy style, vintage, by tim burton style --ar 2:3 --v 5.2 <\br> Neo-expressionism of 新表现主义 cartoonish pluto 卡通般的冥王星 in the style of 在拉、刮和划痕的风格 pulled, scraped, and scratched meditative 冥想 unconventional poses 非常规姿势 spiky mounds 尖锐的土堆 1970s 1970年代 twisted characters 扭曲的人物 soggy Banksy style 湿漉漉的Banksy风格 vintage 复古 by tim burton style 蒂姆·伯顿风格

![alt](https://d1tbi5ymsmhzj2.cloudfront.net/attachments/933565701162168371/1124782195991658527/RikeR_Neo-expressionism_of_a_cartoonish_pluto__in_the_style_of__db1cabb8-2b2d-4715-9865-9a4a8e51b671.webp)
