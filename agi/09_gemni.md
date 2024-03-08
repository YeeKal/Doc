---
title: gemini model
categories: 
tags: 
date: 2024-01-15
---

- [Gemini-Next-Web](https://github.com/blacksev/Gemini-Next-Web/tree/main)

- 官方api文档： https://ai.google.dev/tutorials/python_quickstart
- 个人建站 https://github.com/babaohuang/GeminiProChat
- 在先体验： https://googlegemini.co/
- [https://simonmy.com/posts/使用vercel反向代理google-palm-api.html](https://simonmy.com/posts/%E4%BD%BF%E7%94%A8vercel%E5%8F%8D%E5%90%91%E4%BB%A3%E7%90%86google-palm-api.html)
- https://chatkit.app/?chat=QaOhivxOtGdUQ1_r3gwda
- https://app.anakin.ai/

当前方案：

- [vercel proxy](https://github.com/Jazee6/gemini-proxy/tree/master)


'''bash
curl https://gemni.yeekal.store/v1beta/models/gemini-pro:generateContent?key=$API_KEY     -H 'Content-Type: application/json'     -X POST     -d '{
      "contents": [{
        "parts":[{
          "text": "Write a story about a magic backpack."}]}]}' 2> /dev/null
{
  "error": {
    "code": 400,
    "message": "User location is not supported for the API use.",
    "status": "FAILED_PRECONDITION"
  }
}

'''