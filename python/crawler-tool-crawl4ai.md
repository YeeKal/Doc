---
title: Crawl4ai
categories: 
tags: 
is_draft: true
date: 2024-08-20
keywords: 
cover: 
description: 
---

- [Crawl4ai homepage](https://crawl4ai.com/mkdocs/demo/)
- []()
- [intro blog](https://medium.com/@honeyricky1m3/crawl4ai-automating-web-crawling-and-data-extraction-for-ai-agents-33c9c7ecfa26)

## Features

1. extract data from web pages

```python
from crawl4ai import WebCrawler

# Create an instance of WebCrawler
crawler = WebCrawler()

# Warm up the crawler (load necessary models)
crawler.warmup()

# Run the crawler on a URL
result = crawler.run(url="https://openai.com/api/pricing/")

# Print the extracted content
print(result.markdown)
```
2. data structuring using llm