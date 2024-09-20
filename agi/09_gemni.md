---
title: gemini model
categories: 
tags: 
date: 2024-01-15
---

- [Gemini-Next-Web](https://github.com/blacksev/Gemini-Next-Web/tree/main)

## 官方api文档： 
  - [gemini api](https://ai.google.dev/gemini-api/docs/api-key)
  - [embedding](https://ai.google.dev/gemini-api/docs/embeddings#curl)
  - [dashboard](https://console.cloud.google.com/apis/api/aiplatform.googleapis.com/cost?project=compact-moment-427102-t4)
- 个人建站 https://github.com/babaohuang/GeminiProChat

## proxy&workers

proxy:

- [https://simonmy.com/posts/使用vercel反向代理google-palm-api.html](https://simonmy.com/posts/%E4%BD%BF%E7%94%A8vercel%E5%8F%8D%E5%90%91%E4%BB%A3%E7%90%86google-palm-api.html)
- https://chatkit.app/?chat=QaOhivxOtGdUQ1_r3gwda
- https://app.anakin.ai/
- [vercel proxy](https://github.com/Jazee6/gemini-proxy/tree/master)


'''bash
curl https://gemni.yeekal.store/v1beta/models/gemini-pro:generateContent?key=$GEMINI_TOKEN     -H 'Content-Type: application/json'     -X POST     -d '{
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
generativelanguage.googleapis.com -> gemni.yeekal.store
embedding
```
curl "https://gemni.yeekal.store/v1beta/models/text-embedding-004:embedContent?key=$GOOGLE_API_KEY" \
-H 'Content-Type: application/json' \
-d '{"model": "models/text-embedding-004",
     "content": {
     "parts":[{
     "text": "Hello world"}]}, }' 2> /dev/null | head
```

- price: https://ai.google.dev/pricing
- [vertex dashboard](https://console.cloud.google.com/apis/api/aiplatform.googleapis.com/metrics?hl=en&project=compact-moment-427102-t4)