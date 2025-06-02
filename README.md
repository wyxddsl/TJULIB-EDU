### 2025年同济大学VEX新生赛程序模板代码
  1. 修改项目名称：打开`.vscode/vex_project_settings.json`文件,修改`project`的`name`属性,修改烧录端口请使用插件的按键
  2. 模板给出基本代码框架,请根据每个文件的提示完成修改任务,主要修改`src`目录下的`main.cpp`、`pidControl.cpp`、`robot-config.cpp`,`include`目录下的`robot-config.h`文件和`tjulib-chassis/ordinary-chassis/ordistraight.hpp`文件,鼓励自己研究并编写定位系统
  3. 如果你需要自己实现一些其他方法,请在include文件夹中定义(参考地盘类实现方式),并记得在`tjulib.h`头文件中声明