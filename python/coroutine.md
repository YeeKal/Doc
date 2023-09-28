---
title: 异步IO（asynchronous IO）
categories: 
tags: 
date: 2023-09-26
---

## Coroutine 协程

## asyncio

协程官方库

## aiohttp


针对web的io操作

```python
import aiohttp
import asyncio
import time


async def getPokemon(session, url):
    async with session.get(url) as resp:
        pokemon = await resp.json()
        return pokemon['name']

async def main(loop):
    async with aiohttp.ClientSession(loop=loop) as session:
        tasks = []
        for number in  range(1,151):
            url = f'https://pokeapi.co/api/v2/pokemon/{number}'
            tasks.append(asyncio.ensure_future(getPokemon(session, url)))

        original_pokemon = await asyncio.gather(*tasks)
        return original_pokemon

if __name__ == '__main__':
    start_time = time.time()
    loop = asyncio.get_event_loop()
    pokemons = loop.run_until_complete(main(loop))
    print("elapse time:{:.3f}, pokemon num:{}".format(time.time()-start_time, len(pokemons)))

```

- [Making an Unlimited Number of Requests with Python aiohttp + pypeln](https://medium.com/@cgarciae/making-an-infinite-number-of-requests-with-python-aiohttp-pypeln-3a552b97dc95)

## httpx