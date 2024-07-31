---
title: React
categories: 
tags: 
is_draft: false
date: 2024-04-08
keywords: 
cover: 
description: 
---

## 参考

- [react-foundations](https://nextjs.org/learn/react-foundations/displaying-data-with-props)

## 基于JSX的组件

利用jsx语法定义组件。组件是一个函数，接受props参数，返回一个React元素。

```jsx
function Header({ title }) {
  console.log(title);
  return <h1>title</h1>;
}
```

## props变量访问

```jsx
// dot notation
function Header(props) {
  return <h1>{props.title}</h1>;
}

// template literal
function Header({title}){
    return <h1>{'Cool ${title}'}</h1>
}

// return by a function
function createTitle(title) {
  if (title) {
    return title;
  } else {
    return 'Default title';
  }
}
 
function Header({ title }) {
  return <h1>{createTitle(title)}</h1>;
}

// ternary operator(三元表达式)
function Header({ title }) {
  return <h1>{title ? title : 'Default Title'}</h1>;
}
```

## 列表生成

```jsx
function HomePage(){
    const names = ['yee', 'ella', 'gege'];

    return (
        <div>
            <Header title="Hello"/>
            <ul>
                {names.map((name) => (
                    <li key={name}>{name}</li>
                ))}
            </ul>
        </div>
    );
}
```

## State and hooks

```jsx
// 'likes' is state, 'setLikes' is a function to update state
const [likes, setLikes] = React.useState(0);

function HomePage() {
  // ...
  const [likes, setLikes] = React.useState(0);
 
  function handleClick() {
    setLikes(likes + 1);
  }
 
  return (
    <div>
      <button onClick={handleClick}>Likes ({likes})</button>
    </div>
  );
}

```