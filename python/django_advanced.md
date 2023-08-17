---
title: adjango 进阶实践
categories: python
tags: django
date: 2023-08-14
---

## live search

**<font color='Tomato'>中文拼音输入</font>**

在输入中文（包括语音识别时）会先后触发compositionstart、compositionend事件，类似于keydown和keyup的组合。在compositionstart事件中，我们可以将输入框的值保存起来，然后在compositionend事件中，我们可以将输入框的值与保存的值进行比较，如果不相等，说明是中文输入，如果相等，说明是英文输入。

```js
// 使用全局变量 is_composing 来标记是否正在输入中文
var is_composing = false;
user_input_var.on('compositionstart', function () {
    is_composing = true;
});
user_input_var.on('compositionend', function () {
    is_composing = false;
});
user_input_var.on('keyup', function () {
    if (is_composing) {
        return;
    }
    const request_parameters = {
        q: $(this).val() // value of user_input_var: the HTML element with ID user-input
    }

    // if scheduled_function is NOT false, cancel the execution of the function
    if (scheduled_function) {
        clearTimeout(scheduled_function)
    }

    // setTimeout returns the ID of the function to be executed
    scheduled_function = setTimeout(ajax_call, delay_by_in_ms, endpoint, request_parameters)

})
``` 

