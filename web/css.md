*css*


**[intro](#intro)**

**[basic](#basic)**

​	[css definition](#css-definition)

​	[css rules](#css-rules)

​	[css comments](#css-coments)	

**[text property](#text-property)**

​	[font](#font)

​	[text](#text)	

**[element](#element)**

​	[box model](#box-model)

​	[size](#size)

​	[background](#background)

​	[list style](#list-style)

​	[table style](#table-style)

​	[link style](#link-style)

​	[mouse cursor](#mouse-cursor)

**[css3 basic](#css3-basic)**

​	[rounded corners](#rounded-corners)

​	[box-shadow](#box-shadow)

​	[transparency effect](#transparency-effect)

​	[presudo](#presudo)

​	[world-wrap](#world-wrap)

​	[@font-face](#font-face)

​	[gradients](#gradients)

​	[background-](#background-)

​	[opacity](#opacity)

**[trans](#trans)**

​	[transition](#transition)

​	[transform](#transform)

​	[animation](#animation)

​	[3dtransform](#3dtransform)


## blur

```html
<div data-overlay="true" style="pointer-events: auto; position: relative; z-index: 13;"><div style="width: 100vw; height: 100vh; position: fixed; top: 0px; left: 0px; display: flex; align-items: flex-start; justify-content: center; pointer-events: auto;"><div style="position: absolute;backdrop-filter: blur(10px);inset: 0px;background: rgba(15, 15, 15, 0);"></div><div role="dialog" tabindex="0" style="position: relative; z-index: 1; box-shadow: rgba(15, 15, 15, 0.1) 0px 0px 0px 1px, rgba(15, 15, 15, 0.2) 0px 5px 10px, rgba(15, 15, 15, 0.4) 0px 15px 40px; border-radius: 12px; background: rgb(37, 37, 37); margin-bottom: 0px; top: 90px; overflow: hidden; width: 75%; min-height: 50px; max-height: 80vh; transform: translate3d(0px, 0px, 0px); max-width: 660px;"><div class="notion-search-menu" style="display: flex; flex-direction: column; min-width: 180px; max-width: calc(100vw - 24px); height: 100%; max-height: 80vh; min-height: 50px;"><div style="flex-grow: 1; min-height: 0px; transform: translateZ(0px); display: flex; flex-flow: row nowrap; justify-content: space-between; max-height: 80vh;"><div style="flex: 1 1 0%; overflow: hidden; display: flex; flex-direction: column;"><div style="display: flex; align-items: center; border: none; padding: 0px 16px 0px 12px; width: 100%; background: transparent; font-size: 18px; line-height: inherit; height: 48px; flex-grow: 0; flex-shrink: 0; z-index: 1; box-shadow: rgba(255, 255, 255, 0.094) 0px 1px 0px;"><div style="margin-right: 6px;"><div style="height: 24px; width: 24px; display: flex; align-items: center; justify-content: center;"><svg viewBox="0 0 16 16" class="search" style="width: 16px; height: 16px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M.281 6.438c0-.875.164-1.696.492-2.461a6.484 6.484 0 011.375-2.032A6.237 6.237 0 016.64.078 6.2 6.2 0 019.11.57c.77.328 1.447.787 2.03 1.375a6.374 6.374 0 011.368 2.032c.333.765.5 1.586.5 2.46 0 .688-.107 1.342-.32 1.961a6.28 6.28 0 01-.868 1.696l3.563 3.578c.11.104.19.226.242.367.057.14.086.29.086.445 0 .22-.05.417-.149.594a1.122 1.122 0 01-1 .57c-.156 0-.307-.028-.453-.086a1.058 1.058 0 01-.382-.25l-3.586-3.585c-.5.333-1.047.596-1.641.789a6.089 6.089 0 01-1.86.28 6.237 6.237 0 01-2.468-.491 6.4 6.4 0 01-2.024-1.367A6.509 6.509 0 01.773 8.913a6.256 6.256 0 01-.492-2.476zm1.664 0c0 .65.12 1.26.36 1.828a4.775 4.775 0 001.015 1.5c.433.427.933.763 1.5 1.007a4.548 4.548 0 001.82.368c.652 0 1.261-.123 1.829-.368a4.747 4.747 0 002.508-2.507 4.567 4.567 0 00.367-1.829c0-.645-.123-1.252-.367-1.82a4.776 4.776 0 00-1.016-1.5A4.578 4.578 0 008.469 2.11a4.567 4.567 0 00-1.828-.367c-.646 0-1.253.123-1.82.367a4.667 4.667 0 00-1.5 1.008c-.433.432-.772.932-1.016 1.5a4.633 4.633 0 00-.36 1.82z"></path></svg></div></div><div style="position: relative; width: 100%;"><input placeholder="Search yeekal's Notion…" type="text" style="font-size: inherit; line-height: inherit; border: none; background: none; width: 100%; display: block; resize: none; padding: 0px; min-width: 0px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis;"><div style="color: rgba(255, 255, 255, 0.443); position: absolute; top: 0px; pointer-events: none; width: 100%; white-space: pre; overflow: hidden; text-overflow: ellipsis;"></div></div></div><div style="display: flex; align-items: center;"><div style="position: relative; flex-grow: 0; overflow: hidden;"><div class="notion-scroller horizontal" style="display: flex; align-items: center; padding: 10px 12px; z-index: 1; overflow: auto hidden; margin-right: 0px; margin-bottom: 0px;"><div style="border-radius: 14px; margin-right: 6px; display: inline-flex;"><div role="button" tabindex="0" style="user-select: none; transition: background 20ms ease-in 0s; cursor: pointer; font-size: 14px; display: inline-flex; align-items: center; justify-content: center; white-space: nowrap; border-radius: 32px; height: 24px; line-height: 24px; padding: 0px 8px; border: 1px solid rgba(255, 255, 255, 0.13); color: rgba(255, 255, 255, 0.443);"><svg viewBox="0 0 16 16" class="arrowsUpDown" style="width: 16px; height: 100%; display: block; fill: currentcolor; flex-shrink: 0; backface-visibility: hidden; margin-right: 6px;"><path d="M4.11 2.385a.61.61 0 01.48-.211c.191 0 .353.07.486.21L8.03 5.409a.66.66 0 01.2.475c0 .191-.061.347-.182.469a.627.627 0 01-.463.181.59.59 0 01-.451-.187L5.926 5.098l-.72-.844.04 1.219v7.242a.624.624 0 01-.187.469.624.624 0 01-.47.187.636.636 0 01-.468-.187.635.635 0 01-.182-.47V5.474l.041-1.22-.726.845-1.201 1.248a.61.61 0 01-.457.187.627.627 0 01-.463-.181.634.634 0 01-.182-.47.66.66 0 01.2-.474l2.958-3.023zm7.786 10.781a.636.636 0 01-.486.205.665.665 0 01-.486-.205l-2.947-3.035a.64.64 0 01-.206-.475c0-.191.061-.345.182-.463a.634.634 0 01.469-.181c.18 0 .33.06.451.181l1.201 1.248.727.85-.041-1.219V2.824c0-.187.06-.342.181-.463a.636.636 0 01.47-.187.627.627 0 01.65.65v7.248l-.041 1.219.726-.85 1.207-1.248a.6.6 0 01.451-.181c.188 0 .342.06.463.181a.615.615 0 01.182.463.648.648 0 01-.2.475l-2.953 3.035z"></path></svg>Sort<svg viewBox="0 0 30 30" class="chevronDown" style="width: 10px; height: 100%; display: block; fill: rgba(255, 255, 255, 0.282); flex-shrink: 0; backface-visibility: hidden; margin-left: 4px; margin-top: 1px;"><polygon points="15,17.4 4.8,7 2,9.8 15,23 28,9.8 25.2,7 "></polygon></svg></div></div><div style="height: 16px; width: 1px; border-radius: 1px; background-color: rgba(255, 255, 255, 0.055);"></div><div style="display: flex; margin: 0px 0px 0px 6px; flex-shrink: 0;"><div style="display: flex; flex-direction: row;"><div style="display: flex;"><div style="border-radius: 14px; margin-right: 6px; display: inline-flex;"><div role="button" tabindex="0" style="user-select: none; transition: background 20ms ease-in 0s; cursor: pointer; font-size: 14px; display: inline-flex; align-items: center; justify-content: center; white-space: nowrap; border-radius: 32px; height: 24px; line-height: 24px; padding: 0px 8px; border: 1px solid rgba(255, 255, 255, 0.13); color: rgba(255, 255, 255, 0.443);"><svg viewBox="0 0 14 10" class="title" style="width: 16px; height: 16px; display: block; fill: currentcolor; flex-shrink: 0; backface-visibility: hidden; margin-right: 6px;"><path d="M10.674 9.45c.293 0 .576-.052.85-.153.273-.098.515-.238.726-.422.215-.184.383-.4.504-.65h.03v.662a.569.569 0 00.163.416c.11.101.25.152.422.152a.579.579 0 00.428-.164c.11-.105.164-.256.164-.451V4.973c0-.43-.104-.805-.31-1.125-.208-.32-.5-.569-.88-.744-.378-.18-.828-.27-1.347-.27-.594 0-1.114.115-1.559.346-.445.226-.75.533-.914.92-.031.07-.056.14-.076.21a.684.684 0 00-.03.194c0 .148.05.27.147.363.102.09.23.135.387.135a.61.61 0 00.287-.064.555.555 0 00.217-.2c.172-.32.377-.554.615-.703.238-.148.533-.223.885-.223.426 0 .76.112 1.002.334.242.223.363.528.363.915v.486l-1.828.1c-.77.042-1.361.23-1.775.562-.41.328-.616.773-.616 1.336 0 .379.09.71.27.996.183.285.435.508.756.668.324.16.697.24 1.119.24zm.328-.938c-.367 0-.666-.092-.897-.276a.906.906 0 01-.345-.738.86.86 0 01.34-.709c.23-.184.558-.29.984-.322l1.664-.106v.598c0 .293-.078.557-.234.791a1.69 1.69 0 01-.627.557c-.266.136-.56.205-.885.205zM.689 9.414c.2 0 .354-.045.463-.135.114-.086.202-.234.264-.445l.65-1.816h3.346l.65 1.816c.063.21.149.36.258.445.114.09.268.135.463.135.207 0 .371-.057.492-.17a.593.593 0 00.188-.463c0-.129-.027-.27-.082-.422L4.79 1.357c-.09-.246-.22-.43-.393-.55C4.23.686 4.012.625 3.742.625c-.508 0-.847.244-1.02.732L.116 8.39a1.3 1.3 0 00-.076.404c0 .195.057.348.17.457.117.11.277.164.48.164zm1.717-3.486L3.73 2.119h.03l1.324 3.809H2.406z"></path></svg><span><div style="max-width: 220px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">Title only  </div></span></div></div></div></div><div style="display: flex; flex-direction: row;"><div style="display: flex;"><div style="display: flex;"><div style="border-radius: 14px; margin-right: 6px; display: inline-flex; opacity: 1;"><div role="button" tabindex="0" style="user-select: none; transition: background 20ms ease-in 0s; cursor: pointer; font-size: 14px; display: inline-flex; align-items: center; justify-content: center; white-space: nowrap; border-radius: 32px; height: 24px; line-height: 24px; padding: 0px 8px; border: 1px solid rgba(255, 255, 255, 0.13); color: rgba(255, 255, 255, 0.443);"><svg viewBox="0 0 16 16" class="person" style="width: 16px; height: 16px; display: block; fill: currentcolor; flex-shrink: 0; backface-visibility: hidden; margin-right: 2px;"><path d="M7.7832 8.00195C9.27344 8.00195 10.5381 6.67578 10.5381 4.95996C10.5381 3.28516 9.2666 2 7.7832 2C6.29297 2 5.01465 3.30566 5.02148 4.97363C5.02148 6.67578 6.28613 8.00195 7.7832 8.00195ZM3.51758 14.3594H12.0352C13.1631 14.3594 13.5527 14.0176 13.5527 13.3887C13.5527 11.6318 11.3242 9.21191 7.77637 9.21191C4.23535 9.21191 2 11.6318 2 13.3887C2 14.0176 2.38965 14.3594 3.51758 14.3594Z"></path></svg><span><div style="max-width: 220px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">Created by  </div></span><svg viewBox="0 0 30 30" class="chevronDown" style="width: 10px; height: 100%; display: block; fill: rgba(255, 255, 255, 0.282); flex-shrink: 0; backface-visibility: hidden; margin-left: 4px; margin-top: 1px;"><polygon points="15,17.4 4.8,7 2,9.8 15,23 28,9.8 25.2,7 "></polygon></svg></div></div></div></div></div><div style="display: flex; flex-direction: row;"></div><div style="display: flex; flex-direction: row;"><div style="display: flex;"><div style="display: flex;"><div style="border-radius: 14px; margin-right: 6px; display: inline-flex; opacity: 1;"><div role="button" tabindex="0" style="user-select: none; transition: background 20ms ease-in 0s; cursor: pointer; font-size: 14px; display: inline-flex; align-items: center; justify-content: center; white-space: nowrap; border-radius: 32px; height: 24px; line-height: 24px; padding: 0px 8px; border: 1px solid rgba(255, 255, 255, 0.13); color: rgba(255, 255, 255, 0.443);"><svg viewBox="0 0 12 14" class="searchInPage" style="width: 16px; height: 16px; display: block; fill: currentcolor; flex-shrink: 0; backface-visibility: hidden; margin-right: 6px;"><path d="M2.877 13.365h6.24c.63 0 1.104-.164 1.424-.492.32-.324.48-.8.48-1.43V6.13c0-.274-.015-.504-.046-.691a1.531 1.531 0 00-.182-.522 2.185 2.185 0 00-.387-.498l-3.07-3.123a2.11 2.11 0 00-.48-.38 1.528 1.528 0 00-.51-.183A3.464 3.464 0 005.7.68H2.877c-.629 0-1.104.164-1.424.492-.32.324-.48.8-.48 1.43v8.841c0 .633.16 1.112.48 1.436.32.324.795.486 1.424.486zm.094-1.154c-.282 0-.492-.072-.633-.217-.14-.144-.211-.351-.211-.621V2.678c0-.27.07-.479.21-.627.142-.149.354-.223.64-.223h2.496V5.04c0 .418.101.73.304.938.207.207.52.31.938.31h3.158v5.086c0 .27-.07.477-.21.621-.142.145-.354.217-.64.217H2.971zm3.855-6.938c-.12 0-.209-.027-.263-.082-.051-.054-.077-.142-.077-.263V1.986l3.229 3.287H6.826z"></path></svg><span><div style="max-width: 220px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">In  </div></span><svg viewBox="0 0 30 30" class="chevronDown" style="width: 10px; height: 100%; display: block; fill: rgba(255, 255, 255, 0.282); flex-shrink: 0; backface-visibility: hidden; margin-left: 4px; margin-top: 1px;"><polygon points="15,17.4 4.8,7 2,9.8 15,23 28,9.8 25.2,7 "></polygon></svg></div></div></div></div></div><div style="display: flex; flex-direction: row;"><div style="display: flex;"><div style="border-radius: 14px; margin-right: 6px; display: inline-flex;"><div role="button" tabindex="0" style="user-select: none; transition: background 20ms ease-in 0s; cursor: pointer; font-size: 14px; display: inline-flex; align-items: center; justify-content: center; white-space: nowrap; border-radius: 32px; height: 24px; line-height: 24px; padding: 0px 8px; border: 1px solid rgba(255, 255, 255, 0.13); color: rgba(255, 255, 255, 0.443);"><svg viewBox="0 0 16 16" class="calendar" style="width: 16px; height: 16px; display: block; fill: currentcolor; flex-shrink: 0; backface-visibility: hidden; margin-right: 6px;"><path d="M3.24902 14.7764H12.6621C14.1455 14.7764 14.918 14.0107 14.918 12.5479V4.22852C14.918 2.76562 14.1455 2 12.6621 2H3.24902C1.77246 2 1 2.75879 1 4.22852V12.5479C1 14.0107 1.77246 14.7764 3.24902 14.7764ZM3.24219 13.416C2.6748 13.416 2.36035 13.1221 2.36035 12.5205V6.23145C2.36035 5.62988 2.6748 5.33594 3.24219 5.33594H12.6689C13.2363 5.33594 13.5508 5.62988 13.5508 6.23145V12.5205C13.5508 13.1221 13.2363 13.416 12.6689 13.416H3.24219ZM6.63965 7.69434H7.04297C7.28906 7.69434 7.37109 7.61914 7.37109 7.37988V6.97656C7.37109 6.73047 7.28906 6.65527 7.04297 6.65527H6.63965C6.39355 6.65527 6.31152 6.73047 6.31152 6.97656V7.37988C6.31152 7.61914 6.39355 7.69434 6.63965 7.69434ZM8.875 7.69434H9.27832C9.51758 7.69434 9.59961 7.61914 9.59961 7.37988V6.97656C9.59961 6.73047 9.51758 6.65527 9.27832 6.65527H8.875C8.62891 6.65527 8.54688 6.73047 8.54688 6.97656V7.37988C8.54688 7.61914 8.62891 7.69434 8.875 7.69434ZM11.1035 7.69434H11.5068C11.7529 7.69434 11.835 7.61914 11.835 7.37988V6.97656C11.835 6.73047 11.7529 6.65527 11.5068 6.65527H11.1035C10.8643 6.65527 10.7822 6.73047 10.7822 6.97656V7.37988C10.7822 7.61914 10.8643 7.69434 11.1035 7.69434ZM4.41113 9.89551H4.80762C5.05371 9.89551 5.13574 9.82031 5.13574 9.57422V9.1709C5.13574 8.93164 5.05371 8.85645 4.80762 8.85645H4.41113C4.16504 8.85645 4.08301 8.93164 4.08301 9.1709V9.57422C4.08301 9.82031 4.16504 9.89551 4.41113 9.89551ZM6.63965 9.89551H7.04297C7.28906 9.89551 7.37109 9.82031 7.37109 9.57422V9.1709C7.37109 8.93164 7.28906 8.85645 7.04297 8.85645H6.63965C6.39355 8.85645 6.31152 8.93164 6.31152 9.1709V9.57422C6.31152 9.82031 6.39355 9.89551 6.63965 9.89551ZM8.875 9.89551H9.27832C9.51758 9.89551 9.59961 9.82031 9.59961 9.57422V9.1709C9.59961 8.93164 9.51758 8.85645 9.27832 8.85645H8.875C8.62891 8.85645 8.54688 8.93164 8.54688 9.1709V9.57422C8.54688 9.82031 8.62891 9.89551 8.875 9.89551ZM11.1035 9.89551H11.5068C11.7529 9.89551 11.835 9.82031 11.835 9.57422V9.1709C11.835 8.93164 11.7529 8.85645 11.5068 8.85645H11.1035C10.8643 8.85645 10.7822 8.93164 10.7822 9.1709V9.57422C10.7822 9.82031 10.8643 9.89551 11.1035 9.89551ZM4.41113 12.0898H4.80762C5.05371 12.0898 5.13574 12.0146 5.13574 11.7754V11.3721C5.13574 11.126 5.05371 11.0508 4.80762 11.0508H4.41113C4.16504 11.0508 4.08301 11.126 4.08301 11.3721V11.7754C4.08301 12.0146 4.16504 12.0898 4.41113 12.0898ZM6.63965 12.0898H7.04297C7.28906 12.0898 7.37109 12.0146 7.37109 11.7754V11.3721C7.37109 11.126 7.28906 11.0508 7.04297 11.0508H6.63965C6.39355 11.0508 6.31152 11.126 6.31152 11.3721V11.7754C6.31152 12.0146 6.39355 12.0898 6.63965 12.0898ZM8.875 12.0898H9.27832C9.51758 12.0898 9.59961 12.0146 9.59961 11.7754V11.3721C9.59961 11.126 9.51758 11.0508 9.27832 11.0508H8.875C8.62891 11.0508 8.54688 11.126 8.54688 11.3721V11.7754C8.54688 12.0146 8.62891 12.0898 8.875 12.0898Z"></path></svg><span><div style="max-width: 220px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">Date  </div></span><svg viewBox="0 0 30 30" class="chevronDown" style="width: 10px; height: 100%; display: block; fill: rgba(255, 255, 255, 0.282); flex-shrink: 0; backface-visibility: hidden; margin-left: 4px; margin-top: 1px;"><polygon points="15,17.4 4.8,7 2,9.8 15,23 28,9.8 25.2,7 "></polygon></svg></div></div></div></div><div style="display: flex; flex-direction: row;"></div><div style="display: flex; flex-direction: row;"></div></div></div></div></div><div style="width: 100%; height: 100%; overflow: hidden auto;"><div id="id_1rl" tabindex="0" role="menu"><div style="margin-bottom: 18px;"><div style="display: flex; padding-left: 14px; padding-right: 14px; margin-top: 6px; margin-bottom: 7px; color: rgba(255, 255, 255, 0.443); fill: rgba(255, 255, 255, 0.443); font-size: 12px; font-weight: 600; line-height: 120%; user-select: none; margin-left: 2px;"><div style="align-self: center; white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">Today</div><div style="margin-left: auto;"><img role="progressbar" class="loading-spinner" alt="Loading..." aria-busy="true" aria-live="polite" src="data:image/svg+xml;utf8,%3Csvg%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%20xmlns%3Axlink%3D%22http%3A%2F%2Fwww.w3.org%2F1999%2Fxlink%22%20xmlns%3Asketch%3D%22http%3A%2F%2Fwww.bohemiancoding.com%2Fsketch%2Fns%22%20width%3D%22100%25%22%20height%3D%22100%25%22%20viewBox%3D%220%200%2024%2024%22%20version%3D%221.1%22%20data-ember-extension%3D%221%22%3E%3Cdefs%3E%3ClinearGradient%20x1%3D%2228.1542969%25%22%20y1%3D%2263.7402344%25%22%20x2%3D%2274.6289062%25%22%20y2%3D%2217.7832031%25%22%20id%3D%22linearGradient-1%22%3E%3Cstop%20stop-color%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20offset%3D%220%25%22%2F%3E%3Cstop%20stop-color%3D%22rgba(164%2C%20164%2C%20164%2C%200)%22%20stop-opacity%3D%220%22%20offset%3D%22100%25%22%2F%3E%3C%2FlinearGradient%3E%3C%2Fdefs%3E%3Cg%20id%3D%22Page-1%22%20stroke%3D%22none%22%20stroke-width%3D%221%22%20fill%3D%22none%22%20%3E%3Cg%20transform%3D%22translate(-236.000000%2C%20-286.000000)%22%3E%3Cg%20transform%3D%22translate(238.000000%2C%20286.000000)%22%3E%3Ccircle%20id%3D%22Oval-2%22%20stroke%3D%22url(%23linearGradient-1)%22%20stroke-width%3D%224%22%20cx%3D%2210%22%20cy%3D%2212%22%20r%3D%2210%22%2F%3E%3Cpath%20d%3D%22M10%2C2%20C4.4771525%2C2%200%2C6.4771525%200%2C12%22%20id%3D%22Oval-2%22%20stroke%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20stroke-width%3D%224%22%2F%3E%3Crect%20id%3D%22Rectangle-1%22%20fill%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20x%3D%228%22%20y%3D%220%22%20width%3D%224%22%20height%3D%224%22%20rx%3D%228%22%2F%3E%3C%2Fg%3E%3C%2Fg%3E%3C%2Fg%3E%3C%2Fsvg%3E" style="visibility: hidden;"></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rm" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">每日资讯</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;"></div></div></div></div></div><div style="margin-bottom: 18px;"><div style="display: flex; padding-left: 14px; padding-right: 14px; margin-top: 6px; margin-bottom: 7px; color: rgba(255, 255, 255, 0.443); fill: rgba(255, 255, 255, 0.443); font-size: 12px; font-weight: 600; line-height: 120%; user-select: none; margin-left: 2px;"><div style="align-self: center; white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">Yesterday</div><div style="margin-left: auto;"><img role="progressbar" class="loading-spinner" alt="Loading..." aria-busy="true" aria-live="polite" src="data:image/svg+xml;utf8,%3Csvg%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%20xmlns%3Axlink%3D%22http%3A%2F%2Fwww.w3.org%2F1999%2Fxlink%22%20xmlns%3Asketch%3D%22http%3A%2F%2Fwww.bohemiancoding.com%2Fsketch%2Fns%22%20width%3D%22100%25%22%20height%3D%22100%25%22%20viewBox%3D%220%200%2024%2024%22%20version%3D%221.1%22%20data-ember-extension%3D%221%22%3E%3Cdefs%3E%3ClinearGradient%20x1%3D%2228.1542969%25%22%20y1%3D%2263.7402344%25%22%20x2%3D%2274.6289062%25%22%20y2%3D%2217.7832031%25%22%20id%3D%22linearGradient-1%22%3E%3Cstop%20stop-color%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20offset%3D%220%25%22%2F%3E%3Cstop%20stop-color%3D%22rgba(164%2C%20164%2C%20164%2C%200)%22%20stop-opacity%3D%220%22%20offset%3D%22100%25%22%2F%3E%3C%2FlinearGradient%3E%3C%2Fdefs%3E%3Cg%20id%3D%22Page-1%22%20stroke%3D%22none%22%20stroke-width%3D%221%22%20fill%3D%22none%22%20%3E%3Cg%20transform%3D%22translate(-236.000000%2C%20-286.000000)%22%3E%3Cg%20transform%3D%22translate(238.000000%2C%20286.000000)%22%3E%3Ccircle%20id%3D%22Oval-2%22%20stroke%3D%22url(%23linearGradient-1)%22%20stroke-width%3D%224%22%20cx%3D%2210%22%20cy%3D%2212%22%20r%3D%2210%22%2F%3E%3Cpath%20d%3D%22M10%2C2%20C4.4771525%2C2%200%2C6.4771525%200%2C12%22%20id%3D%22Oval-2%22%20stroke%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20stroke-width%3D%224%22%2F%3E%3Crect%20id%3D%22Rectangle-1%22%20fill%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20x%3D%228%22%20y%3D%220%22%20width%3D%224%22%20height%3D%224%22%20rx%3D%228%22%2F%3E%3C%2Fg%3E%3C%2Fg%3E%3C%2Fg%3E%3C%2Fsvg%3E" style="visibility: hidden;"></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rn" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">page</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;"></div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1ro" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">工具网页</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;"></div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rp" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">tools</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;"></div></div></div></div></div><div style="margin-bottom: 18px;"><div style="display: flex; padding-left: 14px; padding-right: 14px; margin-top: 6px; margin-bottom: 7px; color: rgba(255, 255, 255, 0.443); fill: rgba(255, 255, 255, 0.443); font-size: 12px; font-weight: 600; line-height: 120%; user-select: none; margin-left: 2px;"><div style="align-self: center; white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">Past Week</div><div style="margin-left: auto;"><img role="progressbar" class="loading-spinner" alt="Loading..." aria-busy="true" aria-live="polite" src="data:image/svg+xml;utf8,%3Csvg%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%20xmlns%3Axlink%3D%22http%3A%2F%2Fwww.w3.org%2F1999%2Fxlink%22%20xmlns%3Asketch%3D%22http%3A%2F%2Fwww.bohemiancoding.com%2Fsketch%2Fns%22%20width%3D%22100%25%22%20height%3D%22100%25%22%20viewBox%3D%220%200%2024%2024%22%20version%3D%221.1%22%20data-ember-extension%3D%221%22%3E%3Cdefs%3E%3ClinearGradient%20x1%3D%2228.1542969%25%22%20y1%3D%2263.7402344%25%22%20x2%3D%2274.6289062%25%22%20y2%3D%2217.7832031%25%22%20id%3D%22linearGradient-1%22%3E%3Cstop%20stop-color%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20offset%3D%220%25%22%2F%3E%3Cstop%20stop-color%3D%22rgba(164%2C%20164%2C%20164%2C%200)%22%20stop-opacity%3D%220%22%20offset%3D%22100%25%22%2F%3E%3C%2FlinearGradient%3E%3C%2Fdefs%3E%3Cg%20id%3D%22Page-1%22%20stroke%3D%22none%22%20stroke-width%3D%221%22%20fill%3D%22none%22%20%3E%3Cg%20transform%3D%22translate(-236.000000%2C%20-286.000000)%22%3E%3Cg%20transform%3D%22translate(238.000000%2C%20286.000000)%22%3E%3Ccircle%20id%3D%22Oval-2%22%20stroke%3D%22url(%23linearGradient-1)%22%20stroke-width%3D%224%22%20cx%3D%2210%22%20cy%3D%2212%22%20r%3D%2210%22%2F%3E%3Cpath%20d%3D%22M10%2C2%20C4.4771525%2C2%200%2C6.4771525%200%2C12%22%20id%3D%22Oval-2%22%20stroke%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20stroke-width%3D%224%22%2F%3E%3Crect%20id%3D%22Rectangle-1%22%20fill%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20x%3D%228%22%20y%3D%220%22%20width%3D%224%22%20height%3D%224%22%20rx%3D%228%22%2F%3E%3C%2Fg%3E%3C%2Fg%3E%3C%2Fg%3E%3C%2Fsvg%3E" style="visibility: hidden;"></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rq" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="pageEmpty" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">Untitled</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">Security Key</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 27</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rr" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="pageEmpty" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">Untitled</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">Security Key</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 27</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rs" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">Security Key</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; visibility: hidden; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 27</div></div></div></div></div><div style="margin-bottom: 18px;"><div style="display: flex; padding-left: 14px; padding-right: 14px; margin-top: 6px; margin-bottom: 7px; color: rgba(255, 255, 255, 0.443); fill: rgba(255, 255, 255, 0.443); font-size: 12px; font-weight: 600; line-height: 120%; user-select: none; margin-left: 2px;"><div style="align-self: center; white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">Past 30 Days</div><div style="margin-left: auto;"><img role="progressbar" class="loading-spinner" alt="Loading..." aria-busy="true" aria-live="polite" src="data:image/svg+xml;utf8,%3Csvg%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%20xmlns%3Axlink%3D%22http%3A%2F%2Fwww.w3.org%2F1999%2Fxlink%22%20xmlns%3Asketch%3D%22http%3A%2F%2Fwww.bohemiancoding.com%2Fsketch%2Fns%22%20width%3D%22100%25%22%20height%3D%22100%25%22%20viewBox%3D%220%200%2024%2024%22%20version%3D%221.1%22%20data-ember-extension%3D%221%22%3E%3Cdefs%3E%3ClinearGradient%20x1%3D%2228.1542969%25%22%20y1%3D%2263.7402344%25%22%20x2%3D%2274.6289062%25%22%20y2%3D%2217.7832031%25%22%20id%3D%22linearGradient-1%22%3E%3Cstop%20stop-color%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20offset%3D%220%25%22%2F%3E%3Cstop%20stop-color%3D%22rgba(164%2C%20164%2C%20164%2C%200)%22%20stop-opacity%3D%220%22%20offset%3D%22100%25%22%2F%3E%3C%2FlinearGradient%3E%3C%2Fdefs%3E%3Cg%20id%3D%22Page-1%22%20stroke%3D%22none%22%20stroke-width%3D%221%22%20fill%3D%22none%22%20%3E%3Cg%20transform%3D%22translate(-236.000000%2C%20-286.000000)%22%3E%3Cg%20transform%3D%22translate(238.000000%2C%20286.000000)%22%3E%3Ccircle%20id%3D%22Oval-2%22%20stroke%3D%22url(%23linearGradient-1)%22%20stroke-width%3D%224%22%20cx%3D%2210%22%20cy%3D%2212%22%20r%3D%2210%22%2F%3E%3Cpath%20d%3D%22M10%2C2%20C4.4771525%2C2%200%2C6.4771525%200%2C12%22%20id%3D%22Oval-2%22%20stroke%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20stroke-width%3D%224%22%2F%3E%3Crect%20id%3D%22Rectangle-1%22%20fill%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20x%3D%228%22%20y%3D%220%22%20width%3D%224%22%20height%3D%224%22%20rx%3D%228%22%2F%3E%3C%2Fg%3E%3C%2Fg%3E%3C%2Fg%3E%3C%2Fsvg%3E" style="visibility: hidden;"></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rt" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">数字游民计划</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 25</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1ru" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px; background: rgba(255, 255, 255, 0.055);"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">搜索&amp;数据</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto;"><div style="display: flex;"><svg viewBox="0 0 16 16" class="enter" style="width: 16px; height: 16px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden; opacity: 1;"><path d="M5.38965 14.1667C5.81812 14.1667 6.10156 13.8767 6.10156 13.468C6.10156 13.2571 6.01587 13.0989 5.89062 12.967L4.18994 11.3125L3.02979 10.3369L4.55908 10.4028H12.7922C14.4402 10.4028 15.1389 9.65796 15.1389 8.04297V4.13403C15.1389 2.48608 14.4402 1.78735 12.7922 1.78735H9.13379C8.70532 1.78735 8.4021 2.11035 8.4021 2.50586C8.4021 2.90137 8.69873 3.22437 9.13379 3.22437H12.7593C13.4316 3.22437 13.7151 3.50781 13.7151 4.17358V7.99683C13.7151 8.67578 13.425 8.95923 12.7593 8.95923H4.55908L3.02979 9.03174L4.18994 8.04956L5.89062 6.39502C6.01587 6.26978 6.10156 6.11157 6.10156 5.89404C6.10156 5.48535 5.81812 5.19531 5.38965 5.19531C5.21167 5.19531 5.01392 5.27441 4.8689 5.41943L1.08521 9.1438C0.933594 9.28882 0.854492 9.48657 0.854492 9.68433C0.854492 9.87549 0.933594 10.0732 1.08521 10.2183L4.8689 13.9492C5.01392 14.0876 5.21167 14.1667 5.38965 14.1667Z"></path></svg></div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rv" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">文史哲笔记</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 24</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rw" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">AIGC</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 23</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rx" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">数字游民&amp;自由职业</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 22</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1ry" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">新闻&amp;咨询网站</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 22</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1rz" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">movie</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 19</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1s0" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="pageEmpty" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">量子计算</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 19</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1s1" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">todo</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 13</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1s2" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">tool</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 10</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1s3" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">区块链</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 9</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1s4" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">前端</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">知识输入</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">知识输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 9</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1s5" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">知识输入</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; visibility: hidden; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 9</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1s6" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="pageEmpty" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">密码系统</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">输出</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">输出</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 9</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1s7" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">输出</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; visibility: hidden; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 9</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1s8" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="pageEmpty" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">Untitled</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">信息输入</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 9</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1s9" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">浪漫主义的根源</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文史哲笔记</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 9</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sa" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">文</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; visibility: hidden; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 8</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sb" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">断章 2022</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文史哲笔记</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jul 8</div></div></div></div></div><div style="margin-bottom: 18px;"><div style="display: flex; padding-left: 14px; padding-right: 14px; margin-top: 6px; margin-bottom: 7px; color: rgba(255, 255, 255, 0.443); fill: rgba(255, 255, 255, 0.443); font-size: 12px; font-weight: 600; line-height: 120%; user-select: none; margin-left: 2px;"><div style="align-self: center; white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">Older</div><div style="margin-left: auto;"><img role="progressbar" class="loading-spinner" alt="Loading..." aria-busy="true" aria-live="polite" src="data:image/svg+xml;utf8,%3Csvg%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%20xmlns%3Axlink%3D%22http%3A%2F%2Fwww.w3.org%2F1999%2Fxlink%22%20xmlns%3Asketch%3D%22http%3A%2F%2Fwww.bohemiancoding.com%2Fsketch%2Fns%22%20width%3D%22100%25%22%20height%3D%22100%25%22%20viewBox%3D%220%200%2024%2024%22%20version%3D%221.1%22%20data-ember-extension%3D%221%22%3E%3Cdefs%3E%3ClinearGradient%20x1%3D%2228.1542969%25%22%20y1%3D%2263.7402344%25%22%20x2%3D%2274.6289062%25%22%20y2%3D%2217.7832031%25%22%20id%3D%22linearGradient-1%22%3E%3Cstop%20stop-color%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20offset%3D%220%25%22%2F%3E%3Cstop%20stop-color%3D%22rgba(164%2C%20164%2C%20164%2C%200)%22%20stop-opacity%3D%220%22%20offset%3D%22100%25%22%2F%3E%3C%2FlinearGradient%3E%3C%2Fdefs%3E%3Cg%20id%3D%22Page-1%22%20stroke%3D%22none%22%20stroke-width%3D%221%22%20fill%3D%22none%22%20%3E%3Cg%20transform%3D%22translate(-236.000000%2C%20-286.000000)%22%3E%3Cg%20transform%3D%22translate(238.000000%2C%20286.000000)%22%3E%3Ccircle%20id%3D%22Oval-2%22%20stroke%3D%22url(%23linearGradient-1)%22%20stroke-width%3D%224%22%20cx%3D%2210%22%20cy%3D%2212%22%20r%3D%2210%22%2F%3E%3Cpath%20d%3D%22M10%2C2%20C4.4771525%2C2%200%2C6.4771525%200%2C12%22%20id%3D%22Oval-2%22%20stroke%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20stroke-width%3D%224%22%2F%3E%3Crect%20id%3D%22Rectangle-1%22%20fill%3D%22rgba(164%2C%20164%2C%20164%2C%201)%22%20x%3D%228%22%20y%3D%220%22%20width%3D%224%22%20height%3D%224%22%20rx%3D%228%22%2F%3E%3C%2Fg%3E%3C%2Fg%3E%3C%2Fg%3E%3C%2Fsvg%3E" style="visibility: hidden;"></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sc" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">酒店</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">共享空间</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div><div style="font-size: 12px; line-height: 16px; color: rgba(255, 255, 255, 0.443); white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">...</div></div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">todo项目</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jun 25</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sd" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">婚纱照</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">公开空间</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jun 25</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1se" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">前期准备</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">公开空间</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jun 11</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sf" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><div><div style="width: 100%; height: 100%;"><img src="/icons/arrow-right_blue.svg?mode=dark" referrerpolicy="same-origin" style="display: block; object-fit: cover; border-radius: 3px; width: 19.2px; height: 19.2px; transition: opacity 100ms ease-out 0s;"></div></div></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">Getting started with Projects &amp; Tasks</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">Notion Projects</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">Projects</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jun 11</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sg" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><div style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px;"><div style="height: 14px; width: 14px; font-size: 14px; line-height: 1; margin-left: 0px; color: rgb(246, 246, 246);"><img class="notion-emoji" alt="📈" aria-label="📈" src="data:image/gif;base64,R0lGODlhAQABAIAAAP///wAAACH5BAEAAAAALAAAAAABAAEAAAICRAEAOw==" style="width: 100%; height: 100%; background: url(&quot;/images/emoji/twitter-emoji-spritesheet-64.d3a69865.png&quot;) 47.4576% 100% / 6000% 6000%;"></div></div></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">Sample Project: Performance</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">Notion Projects</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">Projects</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jun 11</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sh" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><div><div style="width: 100%; height: 100%;"><img src="/images/app-packages/task-db-icon.svg" referrerpolicy="same-origin" style="display: block; object-fit: cover; border-radius: 3px; width: 17.76px; height: 17.76px; transition: opacity 100ms ease-out 0s;"></div></div></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">Tasks</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">Notion Projects</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jun 11</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1si" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><div><div style="width: 100%; height: 100%;"><img src="/icons/stars_lightgray.svg?mode=dark" referrerpolicy="same-origin" style="display: block; object-fit: cover; border-radius: 3px; width: 19.2px; height: 19.2px; transition: opacity 100ms ease-out 0s;"></div></div></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">Notion Projects</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; visibility: hidden; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jun 11</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sj" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">日本旅游攻略</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">共享空间</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">日本旅游</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jun 11</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sk" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">哲学史讲演录</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文史哲笔记</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Jun 10</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sl" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">metaphysics</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文史哲笔记</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 19</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sm" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">社会契约论</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">文史哲笔记</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 19</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sn" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">九月临近准备</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">公开空间</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 19</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1so" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">日本旅游</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">共享空间</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 19</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sp" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">共享空间</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; visibility: hidden; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 15</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sq" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">japan travel</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">共享空间</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">日本旅游</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 14</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sr" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">公开空间</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; visibility: hidden; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 14</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1ss" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">旅游路线</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">共享空间</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div><div style="font-size: 12px; line-height: 16px; color: rgba(255, 255, 255, 0.443); white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">...</div></div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">japan travel</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 13</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1st" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">出发前的准备</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">共享空间</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div><div style="font-size: 12px; line-height: 16px; color: rgba(255, 255, 255, 0.443); white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">...</div></div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">japan travel</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 13</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1su" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">大阪</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">共享空间</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div><div style="font-size: 12px; line-height: 16px; color: rgba(255, 255, 255, 0.443); white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">...</div></div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">japan travel</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 6</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sv" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="pageEmpty" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">核酸检测</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">共享空间</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div><div style="font-size: 12px; line-height: 16px; color: rgba(255, 255, 255, 0.443); white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">...</div></div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">calendar</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">May 3</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sw" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="pageEmpty" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">入境准备/电话卡</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">共享空间</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div><div style="font-size: 12px; line-height: 16px; color: rgba(255, 255, 255, 0.443); white-space: nowrap; overflow: hidden; text-overflow: ellipsis;">...</div></div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">calendar</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Apr 22</div></div></div></div><div role="menuitem" tabindex="-1" class="notranslate" id="id_1sx" style="user-select: none; transition: none 0s ease 0s; cursor: pointer; width: calc(100% - 8px); margin-left: 4px; margin-right: 4px; border-radius: 3px; padding-left: 2px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 36px; font-size: 14px; padding-top: 8px; padding-bottom: 8px;"><div style="display: flex; align-items: center; justify-content: center; margin-left: 10px; margin-right: 4px; margin-top: 1px; align-self: center;"><div class="notion-record-icon notranslate" style="display: flex; align-items: center; justify-content: center; height: 20px; width: 20px; border-radius: 0.25em; flex-shrink: 0;"><span role="img"><svg viewBox="0 0 16 16" class="page" style="width: 18px; height: 18px; display: block; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden;"><path d="M4.35645 15.4678H11.6367C13.0996 15.4678 13.8584 14.6953 13.8584 13.2256V7.02539C13.8584 6.0752 13.7354 5.6377 13.1406 5.03613L9.55176 1.38574C8.97754 0.804688 8.50586 0.667969 7.65137 0.667969H4.35645C2.89355 0.667969 2.13477 1.44043 2.13477 2.91016V13.2256C2.13477 14.7021 2.89355 15.4678 4.35645 15.4678ZM4.46582 14.1279C3.80273 14.1279 3.47461 13.7793 3.47461 13.1436V2.99219C3.47461 2.36328 3.80273 2.00781 4.46582 2.00781H7.37793V5.75391C7.37793 6.73145 7.86328 7.20312 8.83398 7.20312H12.5186V13.1436C12.5186 13.7793 12.1836 14.1279 11.5205 14.1279H4.46582ZM8.95703 6.02734C8.67676 6.02734 8.56055 5.9043 8.56055 5.62402V2.19238L12.334 6.02734H8.95703ZM10.4336 9.00098H5.42969C5.16992 9.00098 4.98535 9.19238 4.98535 9.43164C4.98535 9.67773 5.16992 9.86914 5.42969 9.86914H10.4336C10.6797 9.86914 10.8643 9.67773 10.8643 9.43164C10.8643 9.19238 10.6797 9.00098 10.4336 9.00098ZM10.4336 11.2979H5.42969C5.16992 11.2979 4.98535 11.4893 4.98535 11.7354C4.98535 11.9746 5.16992 12.1592 5.42969 12.1592H10.4336C10.6797 12.1592 10.8643 11.9746 10.8643 11.7354C10.8643 11.4893 10.6797 11.2979 10.4336 11.2979Z"></path></svg></span></div></div><div style="margin-left: 4px; margin-right: 6px; min-width: 0px; flex: 1 1 auto; display: inline-flex; align-items: center; width: 100%;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; flex-shrink: 0; max-width: 100%;"><div style="display: flex; justify-content: space-between; font-weight: 500; line-height: 20px;"><div style="display: flex;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-weight: 500; line-height: 20px;">calendar</div></div></div></div><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgb(127, 127, 127); margin-top: 1px; font-size: 12px; display: inline-flex;"><span style="font-size: 12px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; color: rgba(255, 255, 255, 0.13); margin-top: 0px; margin-left: 0.5em; margin-right: 0.5em;">—</span><div style="display: flex; font-size: 12px; color: rgba(255, 255, 255, 0.282); overflow: hidden;"><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">共享空间</div><span style="padding-left: 4px; padding-right: 4px;">/</span><div class="notranslate" style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis; font-size: 12px; color: rgba(255, 255, 255, 0.282);">日本旅游</div></div><div></div></div></div><div style="margin-left: auto; margin-right: 12px; min-width: 0px; flex: 0 0 auto; font-size: 12px; font-weight: 400; color: rgb(90, 90, 90);"><div style="display: flex;">Apr 18</div></div></div></div></div></div><div></div></div><footer style="flex-shrink: 0;"><div style="box-shadow: rgba(255, 255, 255, 0.094) 0px -1px 0px; margin-top: 1px; display: flex; flex-direction: row; justify-content: space-between; align-items: center; font-size: 14px;"><div style="display: flex; align-items: center; line-height: 120%; width: 100%; user-select: none; min-height: 28px; font-size: 12px; color: rgba(255, 255, 255, 0.282); white-space: nowrap; overflow: hidden; text-overflow: ellipsis;"><div style="margin-left: 12px; margin-right: 12px; min-width: 0px; flex: 1 1 auto;"><div style="white-space: nowrap; overflow: hidden; text-overflow: ellipsis;"><ul style="list-style-type: none; padding: 0px; margin: 0px; font-size: 12px; color: rgba(255, 255, 255, 0.282); white-space: nowrap; overflow: hidden; text-overflow: ellipsis;"><li style="display: inline; margin-right: 16px;"><svg viewBox="0 0 16 16" class="arrowsUpDown" style="width: 12px; height: 12px; display: inline; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden; margin-right: 4px; margin-bottom: -2px;"><path d="M4.11 2.385a.61.61 0 01.48-.211c.191 0 .353.07.486.21L8.03 5.409a.66.66 0 01.2.475c0 .191-.061.347-.182.469a.627.627 0 01-.463.181.59.59 0 01-.451-.187L5.926 5.098l-.72-.844.04 1.219v7.242a.624.624 0 01-.187.469.624.624 0 01-.47.187.636.636 0 01-.468-.187.635.635 0 01-.182-.47V5.474l.041-1.22-.726.845-1.201 1.248a.61.61 0 01-.457.187.627.627 0 01-.463-.181.634.634 0 01-.182-.47.66.66 0 01.2-.474l2.958-3.023zm7.786 10.781a.636.636 0 01-.486.205.665.665 0 01-.486-.205l-2.947-3.035a.64.64 0 01-.206-.475c0-.191.061-.345.182-.463a.634.634 0 01.469-.181c.18 0 .33.06.451.181l1.201 1.248.727.85-.041-1.219V2.824c0-.187.06-.342.181-.463a.636.636 0 01.47-.187.627.627 0 01.65.65v7.248l-.041 1.219.726-.85 1.207-1.248a.6.6 0 01.451-.181c.188 0 .342.06.463.181a.615.615 0 01.182.463.648.648 0 01-.2.475l-2.953 3.035z"></path></svg>Select</li><li style="display: inline; margin-right: 16px;"><svg viewBox="0 0 16 16" class="enter" style="width: 11px; height: 11px; display: inline; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden; margin-right: 4px; margin-bottom: -2px;"><path d="M5.38965 14.1667C5.81812 14.1667 6.10156 13.8767 6.10156 13.468C6.10156 13.2571 6.01587 13.0989 5.89062 12.967L4.18994 11.3125L3.02979 10.3369L4.55908 10.4028H12.7922C14.4402 10.4028 15.1389 9.65796 15.1389 8.04297V4.13403C15.1389 2.48608 14.4402 1.78735 12.7922 1.78735H9.13379C8.70532 1.78735 8.4021 2.11035 8.4021 2.50586C8.4021 2.90137 8.69873 3.22437 9.13379 3.22437H12.7593C13.4316 3.22437 13.7151 3.50781 13.7151 4.17358V7.99683C13.7151 8.67578 13.425 8.95923 12.7593 8.95923H4.55908L3.02979 9.03174L4.18994 8.04956L5.89062 6.39502C6.01587 6.26978 6.10156 6.11157 6.10156 5.89404C6.10156 5.48535 5.81812 5.19531 5.38965 5.19531C5.21167 5.19531 5.01392 5.27441 4.8689 5.41943L1.08521 9.1438C0.933594 9.28882 0.854492 9.48657 0.854492 9.68433C0.854492 9.87549 0.933594 10.0732 1.08521 10.2183L4.8689 13.9492C5.01392 14.0876 5.21167 14.1667 5.38965 14.1667Z"></path></svg>Open</li><li style="display: inline; margin-right: 16px;"><span style="font-size: 10.5px; padding-right: 1px; color: rgba(255, 255, 255, 0.282);">ctrl</span><svg viewBox="0 0 16 16" class="enter" style="width: 11px; height: 11px; display: inline; fill: rgba(255, 255, 255, 0.443); flex-shrink: 0; backface-visibility: hidden; margin-right: 4px; margin-bottom: -2px;"><path d="M5.38965 14.1667C5.81812 14.1667 6.10156 13.8767 6.10156 13.468C6.10156 13.2571 6.01587 13.0989 5.89062 12.967L4.18994 11.3125L3.02979 10.3369L4.55908 10.4028H12.7922C14.4402 10.4028 15.1389 9.65796 15.1389 8.04297V4.13403C15.1389 2.48608 14.4402 1.78735 12.7922 1.78735H9.13379C8.70532 1.78735 8.4021 2.11035 8.4021 2.50586C8.4021 2.90137 8.69873 3.22437 9.13379 3.22437H12.7593C13.4316 3.22437 13.7151 3.50781 13.7151 4.17358V7.99683C13.7151 8.67578 13.425 8.95923 12.7593 8.95923H4.55908L3.02979 9.03174L4.18994 8.04956L5.89062 6.39502C6.01587 6.26978 6.10156 6.11157 6.10156 5.89404C6.10156 5.48535 5.81812 5.19531 5.38965 5.19531C5.21167 5.19531 5.01392 5.27441 4.8689 5.41943L1.08521 9.1438C0.933594 9.28882 0.854492 9.48657 0.854492 9.68433C0.854492 9.87549 0.933594 10.0732 1.08521 10.2183L4.8689 13.9492C5.01392 14.0876 5.21167 14.1667 5.38965 14.1667Z"></path></svg>Open in a new tab</li></ul></div></div></div></div></footer></div></div><footer style="flex-shrink: 0;"></footer></div></div></div></div>
```


# intro

**CSS：C**ascading **S**tyle **S**heets, to separate **style** from **content**

# basic

## css definition

**inline CSS**

```html
<p style="color:white;background-color:gray;">
  This is an example off inline styling.
</p>
```

**embeded css**

internal styles defined within **\<style\>** element,inside the **head** section 

```html
<html>
<head>
  <style>
    p{
      color:white;
      background-color:gray;
    }
  </style>
</head>
  
<body>
   <p>I am happy to meet you again!</p> 
</body>
</html>
```

**external css**

styling rules are contained in a single text file saved with .css extension.

```html
<head>
  <link rel="stylesheet" href="example.css">
</head>
```

the **example.css**

```css
p{
  color:white;
  background-color:gray;
}
```

## css rules

**css syntax**

a stle rule has three parts: **selector  property  value**

```css
h1 {color:orange}
```

**type selector**

targets elements types on the page.

for example, to target all the paragraphs on  the page:

```css
p{
  color:red;
  font-size:20px;
}
```

**id selector**

html:

```html
<div id="intro">
  <p>i love you.</p>
</div>
```

css:

```css
#intro{
  color:white;
}
```

**class selector**

html:

```html
<div>
  <p class="sunday">a good day.</p>
  <p class="badday">a rainy day</p>  
</div>

<p class="sunday">another sun day</p>
```

css:

```css
.sunday{
  color:red;
}
.badday{
  color:blue;
}
```

- id can only be applied**once**;while class can be possessed by **many owners**.

**descendant selector**

派生选择器


html:

```html
<div id ="intro">
  <p class="exe1">This paragraph contains <em>this </em>to be selected.</p>
  <p class="exe1">this will not</p>
</div>
```

css:

```css
#intro .exe1 em{
  color:pink;
}
```

## css comments

```css
/* comments here*/
/*
multilines comments;
line;
*/
p{
  color:orange;
}
```

**css cascade and inheritance**

a cascade contains three main sources:

- stylesheets created
- broweser's default styles
- strles specified by users

# text property

## font

**font-family**

- font family: a specific font family
- generic family: a group of font families

five generic family:

- serif
- sans-serif
- monospace
- cursive
- fantasy

```css
p .serif{
  font-family:"times new roman",times,serif;
}
p .monospace{
  font-family:"courier new",courier,monospace;
}
/*
use comma to indicate they are alternative
quotation marks to quote more than one word
add the generic family as a fallback
*/
```

**font-size**

keywords: **x-small, small, medium,large,larger,x-large**

numerical values: **px,em;em=default px**

**font-style**

```css
italic
normal
oblique
/*<i> tag will produce exactly the same result as the italic font style.*/
```

**font-weight**

```css
100-900
normal	400
light
bold	700
bolder
```

**font-variant**

```css
normal
small-caps
```

**color**

color name:	red, white,.....

rgb:	`color:rgb(255,0,0)`defines individual values for red, green, blue

hexadecimal values: `color:#FFFFFF`

## text

**text-align**

```css
left
right
center
justify
/*justify: each line is strenched to get equal width*/
```

**vertical-align**

```css
top
middle
bottom
/* most used in table*/

baseline
sub
super
+/- xx(px/pt/cm)
```

**text-decoration**

```css
none
inherit
overline
underline
line-through

@deprecated
  blink
```

**text-indent**

```css
p{
  text-indent:30px
}
/*negative value is valid*/
```

**text-shadow**

```css
text-shadow:4px 2px 4px grey;
/*
4px - x-coordinate
2px - y-coordinate
4px - the blur radius
grey - the color of the shadow
*/
```

**text-transform**

```css
capitalize
uppercase
lowercase
```

**letter-spacing**

```css
letter-spacing:normal;
letter-spacing:4px;
/*negative value is valid*/
```

**word-spacing**

as above

**white-space**

```css
pre
pre-line
pre-wrap
```

# property

## box model

all html elements can be considered as boxes:

![box model](https://api.sololearn.com/DownloadFile?id=2613)

properties work in the same order: **top right bottom left**

total width: **padding+border+margin+content**

width and height properties: **content**

background-color cover: **content + padding** 

## size

**border**

```css
p{
  padding:10px;
  border:5px solid orange;
}

p{
  padding:10px;
  border-width:5px;
  border-style:solid;
  border-color:orange;
}

/*
none of the border properties will have any effect unless the border-style property is set.
*/
borderstyle:dotted/dashed/double/....
border-top-style
border-right-style
border-bottom-style
border-left-style
```

**width and height**

1. numerical value(pixels)
2. percents

min-width/min-height/max-width/max-height

## background-

**background-color**

**background-image**

```css
background-image:url("URL")
```

**background-repeat**

```css
{
  background-image:url("URL");
  background-repeat:repeat-x;
}
```

repeat-x: horizontal

repeat-y: vertical

no-repeat: show once

repeat:

inherit:	inheritance from parent element

**background-attachment**

sets whether a background image is fixed or scrolls with the rest of the page.

```css
fixed;
scroll;
inherit;
```

## list style

**list-style-type**

[list style all types from w3school](http://www.w3school.com.cn/tiy/t.asp?f=csse_list-style-type_all)

```css
ol .lower-alpha{	/*ordered list*/
  list-style-type:lower-alpha;
}

ul .circle{			/*unordered list*/
  list-style-type:circle;
}
```

**list-style-image**

```css
list-style-image:url("URL");
```

**list-style-position**

```css
list-style-position:inside;
/*outside is the default value*/
```

**list-style**

```css
list-style:square outside none;
/*equals to*/
list-style-type:square;
list-style-position:outside;
list-style-image:none;
/*the missing value will set the default*/

```

## table style

**border-collapse**

- separate:  double borders
- collapse:   single

**border-spacing**

```css
/*distance between two borders*/
border-spacing:20px 40px;
```

**caption-side**

​	specify the placement of table caption

- top
- bottom

**empty-cells**

- show
- hide

**table-layout**

​	specify the width of table columns

- auto (default)
- fixed

## link style

preudo selectors for link:

- a:link  unvisited links
- a:visited  visited links
- a:hover  when the mouse is over it
- a:active  once you click on it

property:

- color
- font-family
- text-decoration (:none)   remove underline
- ...

## mouse cursor

**cursor**: specifies the desired cursor style when you mouse over an element

![possible value](https://api.sololearn.com/DownloadFile?id=2983)

# element

## 列表

```css
ul li{
  display:block;
  float:left;
  width:30px;
}
/*为了让列表项水平显示，将其设置为左浮动。为了定义宽度则设为块级元素*/
/*当然设置为inline内联元素也可以水平，但却不能定义宽度*/
```



## display

**display**

- block:  change an inline element to a block element
- inline:  reverse
- none:  hide elements; as no such element
- list-item
- grid
- ...

**visibility**

- hidden:  remain space without content
- visible

## position

**position**

- static:  default
- fixed:  will not move even the window is scrolled
- relative: relative to its normal position
- absolute

**top/right/bottom/left**

**floating**

​	for img floating in the text

​	for elements next to each other

​	脱离原来的文档流，不占位置

- left
- right
- none

**clear**

elements that come after the floating element will flow around it

use clear

- left
- right
- both





**overflow**

specify the content overflowing the box

- scroll:  add scroll bar
- auto: adding scroll bar when overflow happens, not add if not
- hidden:  the rest remains invisible
- visible: default, no bars

**z-index**

whos num is larger, who lay upper

as seeing from z-axis

position elements is necessary

**对齐**

```css
//水平对齐。'!doctype'
margin-left:auto;
margin-right:auto;
```



# css3 basic

**vender prefixe**

to add support for new css features

```css
-webkit-border-radius:24px;
/*
most browsers today will work without prefixes
it is essential to know these for backgrounds capability
*/
```

![browser prefixes](https://api.sololearn.com/DownloadFile?id=2665)

## rounded corners

```css
border-radius:20px;

/*specify values respectively as order:top-left  top-right  bottom-right  bottom-left*/
border-radius: 0 0 20px 20px;

/*create a circle*/
div{
  height:200px;
  width:200px;
  border-radius:100px;
  background-color:green;
  color:white;
}
```

## box-shadow

```css
box-shadow:10px 10px #888888;
/*
10px:  horizontal offset
10px:  vertical offset
#:     color
for material design
*/

box-shadow:10px 10px 8px -4px #888888;
/*
optional values:
blur and spread
*/
/*values can be set negative except blur-option*/

box-shadow:inset 10px 10px 5px #888888;
/*create an inner shadow with keyword:inset
凹陷/凸起感*/

/*multiple layer*/
box-shadow:
inset 10px 10px 5px #888888,
0 0 10px 30px #ffdab9;
```

## transparency effect

**rgba(red,green,blue,alpha)**

```css
div{ 
background: linear-gradient(90deg, 
     rgba(255, 255, 255, 0) 0%, 
     rgba(255, 255, 255, 0.2) 25%, 
     rgba(255, 255, 255, 0.2) 75%, 
     rgba(255, 255, 255, 0) 100%);
box-shadow: 0 0 25px rgba(0, 0, 0, 0.1),
     inset 0 0 1px rgba(255, 255, 255, 0.6);
}
/*beautiful*/
```

## presudo

**presudo class**

`:`

html:

```css
<div id="parent">
   <p>First paragraph</p>
   <p>Second paragraph</p>
   <p>Third paragraph</p>
   <p>Fourth paragraph</p>
</div>
```

css:

```css
#parent p:first-child {
   color: green;
   text-decoration: underline;   
}
/*matches the first p in div with id named parent*/
/*last-child*/
```

**presudo element**

used to select specific parts of an elements

five elements in css, starting with a double colon `::`

**::first-line** - the first line of the text in a selector

**::first-letter** - the first letter of the text in a selector

**::selection** - selects the portion of an element that is selected by a user

**::before **- inserts some content before an element

**::after** - inserts some content after an element

```css
p::before{
  content:url("img.jpg");
}
```

## word-wrap

```css
word-wrap:normal;	/*a long word not break*/
word-wrap:break-word;	
/*
when the word-wrap property is set to break-word, the browser breaks a word when it is too long for fit within its container.
*/
```

## @fonr-face

allows custom fonts to be loaded into a webpage.

In Internet Explorer 8 and earlier, the URL must point to an **Embedded OpenType** (eot) file, while Firefox, Chrome, etc. support **True Type Fonts** (ttf) fonts and **OpenType Fonts** (otf).

```css
@font-face{
  font-family:delicious;
  src:url('delicilous-roman.otf');
  font-weight:bold;
}

/*ie has a built-in bug when multiple @font-face rules are defined
using #iefix as following example*/
@font-face { 
   font-family: Delicious; 
   src: url('Delicious-Roman.ttf');
   src: url('Delicious-Roman.eot?#iefix'); 
}
```



## gradients

**linear gradient**

```css
background:-moz-linear-gradient(blue 20%, yellow 30%, green 85%);
 background:linear-gradient(white 20%,gray 50%,green 50%,red 80%);
/*sharp color
colorname/rga/rgba/hex values/hsl*/

background:-webkit-linear-gradient(left,white 20%,gray 50%,green 50%,red 80%);
/*
change direction:
left/right/top/botttom/bottom right
0-180deg
*/

background:-moz-repeating-linear-gradient(blue, green 20px);
/*repeating per 20px*/
```

**radical-gradient**

```css
/*universal format*/
radial-gradient(position size/shape color);
/*
shape:
circle
eclipse
position: top left/0% 0%/20px 20px
*/
background:radial-gradient(white 15%,black 				    15%,rgba(200,200,200,0.2) 100%);
```

## background-

**background-size**

specify the size of background images, using either lengths or percentages

```css
div{
  height:150px;
  width:200px;
  border:1px solid #000;
  background:url("css.png") no-repeat 50% 50%;
  background-size:100px 100px;
}

/*keywords*/
contain;
cover;
```

**background-clip**

specify the painting area of the background

still work with image

border-box: (default)

padding-box:

content-box:

```css
border: 20px solid rgba(0, 0, 0, 0.3);
background-clip:padding-box;
/*Transparency effect is achieved with the background-clip:padding-box. Without it, the background of the box also goes beneath the borders, making it non-transparent.*/
```

**multiple backgrounds**

```css
div {
  width: 400px;
  height: 300px;
  background-image: url(csslogo.png), url(csscode.jpg);
  background-position: right bottom, left top;
  background-repeat: no-repeat;
} 
/*another way*/
background: url(csslogo.png) right top no-repeat, 
url(csscode.jpg) left top no-repeat; 
```

## opacity

an excellent means of adding opacity to any element

```css
#img1{
  opacity:0.5;
}
/*opacity value must be between 0.0-1.0*/

/*to work in ie*/
opacity:0.5;
filter.alpha(opacity=50);
```



# trans

## transition

allow us to change one property value to another one over a given duration

**transition-property** - specifies the property to be transitioned
**transition-duration** - specifies the duration over which transitions should occur
**transition-timing-function** - specifies how the pace of the transition changes over its duration
**transition-delay** - specifies a delay (in seconds) for the transition effect

example:

```css
div {
   width: 50px;
   height: 50px;
   background: #32CD32;
   transition: width 3s;
}
div:hover {
   width: 250px;
}
/*if you hover the div element it will anlarge duriing 3 seconds*/
```

**transition-timing-function**

**ease **- the animation starts slowly, then accelerates quickly.
**ease-in** - starts slowly, then accelerates, and stops abruptly.
**ease-out** - starts quickly, but decelerates to a stop.
**ease-in-out** - similar to ease, but with more subtle acceleration and deceleration.
**linear **- constant speed throughout the animation; often best for color or opacity changes.

**cubic-besizer()**: value from0 to 1

```css
transition-timing-function: cubic-bezier(0,0,1,1);
```

## transform

**rotate**

```css
transform:rotate(10deg);/*negative value will generate counter-clockwise*/
```

**transform-origin**

change the position of the transform point

```css
transform:rotate(15deg);
transform-origin:25% 75%;
```

**translate**

```css
transform:translate(100px,50px);/**/
```

**skew**

```css
transform:skew(30deg,30deg);/*平行四边形*/
```

**scale**

```css

```

**multiple trans**

```css
transform:rotate(45deg) translate(100px);/*no comma*/
```

```css
/*transition定义了类型，时间，在动作中定义transform具体的行为*/
div
{
width:100px;
height:100px;
background:yellow;
transition:width 2s, height 2s;
-moz-transition:width 2s, height 2s, -moz-transform 2s; /* Firefox 4 */
-webkit-transition:width 2s, height 2s, -webkit-transform 2s; /* Safari and Chrome */
-o-transition:width 2s, height 2s, -o-transform 2s; /* Opera */
}

div:hover
{
width:200px;
height:200px;
transform:rotate(180deg);
-moz-transform:rotate(180deg); /* Firefox 4 */
-webkit-transform:rotate(180deg); /* Safari and Chrome */
-o-transform:rotate(180deg); /* Opera */
}
```



## animation

```css
div {
   width: 100px;
   height: 100px;
   background-color: red;
   animation-name: colorchange;		/*bind name*/
   animation-duration: 1s;			/*time*/
}
@keyframes colorchange {			/*from to*/
   0% {background-color: red;}
   50% {background-color: green;}
   100% {background-color: blue;}
} 
```

**animation-name**

**animation-duration**

**animation-timing-function**

same as transtion-timing-function

**animation-delay**

​	s/ms(milliseconds)

**animation-iteration-count**

numerical/infinite

```css
animation-iteration-count:5;  /*repeat 5 times*/
```

**animation-direction**

The values can be set as:
normal - the default value, which means it plays forward from 0 % to 100%. 
reverse - plays the keyframe in an opposite direction from 100 % to 0%
alternate - the animation first runs forward, then backward, then forward.

**multiple include**

```css
div {
   animation-name: colorchange;
   animation-duration: 3s;
   animation-timing-function: ease-in;
   animation-delay: 1s;
   animation-iteration-count: infinite;
   animation-direction: reverse;
}
/*can be revised as following*/
div { 
   animation: colorchange 3s ease-in 1s infinite reverse;
}
/*order can not be altered*/
```

## 3dtransform

**rotate**

rotate3d=rotatex+rotatey+rotatez

```css
div.X {
   transform: rotateX(150deg);
}
div.Y {
   transform: rotateY(150deg);
}
div.Z {
   transform: rotateZ(150deg);
}
```

**translate**

```css
#mybox1 {
   transform: translate3d(-20px, 4em, 10px);
}
/*equal to*/
#mybox1 {
   transform: translateX(29px) 
   translateY(5em) 
   translateZ(-13px);
}
```

**percpective**

```css
div.empty-div {
   perspective: 100px;
}
div.green-div {
   transform: rotateX(45deg);
}
/*The perspective property only affects 3D transformed elements.*/
```

