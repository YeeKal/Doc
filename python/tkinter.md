Tkinter

[TOC]

## layout

```python
pack()
self.pack()	#default top
self.pack(side="left")
anchor:
expand:0,1
fill:'x','y','both','none'
padx/pady:
side:
```

```python
grid()
self.button3.grid(row = 1,column = 0,padx = 5,pady = 5)
```



## 事件

```python
#event level1 与实例绑定
command=self.fun#def fun(self)
self.widget.bind('<key>',fun)#def fun(self,event)
event.char#按下的键
#与一类组件绑定
widget.bind_class(“Canvas”, “<Button-2>”, drawline)
#与程序界面绑定
widget.bind_all( “<Key-print>”,fun)
```

## get var

> widget: variable, textvariable, onvalue, offvalue, and value

> StringVar, IntVar, DoubleVar, and BooleanVar

```python
self.contents=StringVar()
self.contents.set('str')
self.widget['textvariable']=self.contents #bind
```

## Tk Option Data Types

> anchor:	n/s/w/e/center

# widgets

## SettingOptions

```python
fred = Button(self, fg="red", bg="blue")	#at object creation time
fred["fg"] = "red"			#after object creation,treating 
fred["bg"] = "blue"			#option name like a dictionary index
fred.config(fg="red", bg="blue")	#update multiple attrs subsequent to object creation
frame['padding'] = (5,10)
```

## label

```python
#display text
resultsContents = StringVar()
label['textvariable'] = resultsContents
resultsContents.set('New value to display')
#display image(.png/)
image=tk.PhotoImage(file='myimage.gif')
label['image']=image
```

## button

```python
#text/image
#command callback
button.invoke()
#state
button.state(['disabled'])            # set the disabled flag, disabling the button
button.state(['!disabled'])           # clear the disabled flag
button.instate(['disabled'])          # return true if the button is disabled, else false
button.instate(['!disabled'])         # return true if the button is not disabled, else false
button.instate(['!disabled'], cmd)    # execute 'cmd' if the button is not disabled
```



