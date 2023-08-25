---
title: Stable Diffusion
categories: 
tags: 
date: 2023-08-25
---

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

| demo1  | demo2  |
|---|---|
| ![robot_stands_on_the_moon](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/download.png)  | ![robot_stands_on_the_moon](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/08/stable_diffusion_robot2.png)  |


- ref links
    - [medium: how to run sdxl 1.0](https://medium.com/@andysingal/how-to-run-sdxl-1-0-model-629048e49e70)

## Stable Diffusion API

- [api reference](https://platform.stability.ai/docs/api-reference#tag/v1user)