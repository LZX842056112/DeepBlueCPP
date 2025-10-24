# Clion控制台输出中文乱码解决方案

1. 在 CLion 顶部菜单栏点：
    **Help → Find Action…**（或者按 `Ctrl+Shift+A` / `⌘⇧A`）。

   <img src="E:\2025-Shenlan\note\c++\images\clion中文输出乱码问题解决.png" style="zoom:50%;" />

2. 输入 **Registry**，回车。

   <img src="E:\2025-Shenlan\note\c++\images\clion中文输出乱码问题解决2.png" style="zoom:50%;" />

3. 在 **Registry** 搜索框里输入：

   ```
   run.process.with.pty
   ```

4. 取消勾选。

<img src="E:\2025-Shenlan\note\c++\images\clion中文输出乱码问题解决3.png" style="zoom:50%;" />