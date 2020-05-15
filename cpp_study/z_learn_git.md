- [1.直接进入沙盒](#1%e7%9b%b4%e6%8e%a5%e8%bf%9b%e5%85%a5%e6%b2%99%e7%9b%92)
- [2. 本地操作相关篇节](#2-%e6%9c%ac%e5%9c%b0%e6%93%8d%e4%bd%9c%e7%9b%b8%e5%85%b3%e7%af%87%e8%8a%82)
  - [2.1 基础篇](#21-%e5%9f%ba%e7%a1%80%e7%af%87)
  - [2.2 处理复杂问题](#22-%e5%a4%84%e7%90%86%e5%a4%8d%e6%9d%82%e9%97%ae%e9%a2%98)
    - [2.2.1 修改提交树](#221-%e4%bf%ae%e6%94%b9%e6%8f%90%e4%ba%a4%e6%a0%91)
  - [2.3 杂项](#23-%e6%9d%82%e9%a1%b9)
- [3. 远程操作相关篇章](#3-%e8%bf%9c%e7%a8%8b%e6%93%8d%e4%bd%9c%e7%9b%b8%e5%85%b3%e7%af%87%e7%ab%a0)
  - [3.1 push && pull----git远程仓库](#31-push--pull----git%e8%bf%9c%e7%a8%8b%e4%bb%93%e5%ba%93)
  - [3.2 关于 origin 和它的周边 —— Git 远程仓库高级操作](#32-%e5%85%b3%e4%ba%8e-origin-%e5%92%8c%e5%ae%83%e7%9a%84%e5%91%a8%e8%be%b9--git-%e8%bf%9c%e7%a8%8b%e4%bb%93%e5%ba%93%e9%ab%98%e7%ba%a7%e6%93%8d%e4%bd%9c)
# 1.直接进入沙盒
在 URL 后头加上 ?NODEMO 就可以了
# 2. 本地操作相关篇节
## 2.1 基础篇
1. Git Commeit
   - 提交记录: 保存的是你的目录下所有文件的快照,就是ctrl+c，但是更优雅、轻便
   - 可以做到的结果：可以快速地在这些提交记录之间切换
   - hide goal命令关闭窗口
2. Git Branch 
   - 分支：早建分支！多用分支！
   - 与上面的提交记录结合起来
     - 一种结合方法：新创建的分支 newImage 指向的是提交记录
       - 切换新分支：``git checkout newImage;git commit``并且修改保存到新分支中
       - 简洁的切换方法(创建新分支并切换新分支)：``git checkout -b <your-branch-name>``
3. Git Merge
   - 用处：两个分支都是独立但是没有整体，如果需要整体的提交记录这时候就可以采用合并分支这一个命令
     - ``git merge bugFix``
   - 合并分支的几个步骤：先切换到a节点，接着合并到b节点
     - 合并的规则就是：正常情况是jiu
  ```
               git branch bugFix
               git commit
               git checkout master
               git merge bugFix
               随时用objective打开对话框
  ```
4. Git Rebase（另外一种合并方案）
   - 本质：实际上就是取出一系列的提交记录，“复制”它们，然后在另外一个地方逐个的放下去（有当前节点和其他节点，rebase就是复制当前节点到其指定的其他节点后面——也就是继承自其他节点）
   - 代码实现：
```
               git checkout -b bugFix  新建并切换回bugFix
               git commit  提交一次
               git checkout master  切换回master
               git commit     再提交一次
               git checkout bugFix  切换回bugFix
               git rebase master    rebase合并到master
```
5. 树上进行移动
   1. HEAD
      - 分离的 HEAD 就是让其指向了某个具体的提交记录而不是分支名
      - 一个对当前检出记录的符号引用 —— 也就是指向你正在其基础上进行工作的提交记录。
      - 总是指向当前分支上最近一次提交记录，修改提交树也是针对head开始的；
      - 对提交做的一些更改，可以通过其看到。
      - 可以通过 cat .git/HEAD 查看head指向；
      - 指向的是一个引用，还可以用 git symbolic-ref HEAD 查看它的指向
``` 
               git checkout C1;
               git checkout master;
               git commit;
               git checkout C2;
```
   2. 分离的 HEAD
      - 让其指向了某个具体的提交记录而不是分支名
      - 待解决的问题：
        - 想完成此关，从 bugFix 分支中分离出 HEAD 并让其指向一个提交记录。
        - 通过哈希值指定提交记录。每个提交记录的哈希值显示在代表提交记录的圆圈中。
  3. 相对引用：
      - 通过指定提交记录哈希值的方式在 Git 中移动不太方便，在git中只需要提供能够唯一标识提交记录的前几个字符即可。
      - 2个非常有用的操作：
        - a.使用 ``^`` 向上移动 1 个提交记录
        - b.使用 ``~<num>`` 向上移动多个提交记录，如 ~3
        - 代码构成：
  ```git
               git checkout C3;
               git checkout HEAD^;
               git checkout HEAD^;
               git checkout HEAD^;
  ```
   - 强制修改分支位置
     - 直接使用 -f 选项让分支指向另一个提交：``git branch -f master HEAD~3``
6. 撤销变更：
   - 组成部分：底层部分（暂存区的独立文件或者片段）和上层部分（变更到底是通过哪种方式被撤销的）
     - 我们关注的是后者：上层部分
   - 两种撤销更改指令：
     - ``git reset``(本地)
     - ``git revert``(远程)：用一个新提交来消除一个历史提交所做的任何修改
   - 完成的任务：
     - 分别撤销 local 分支和 pushed 分支上的最近一次提交。共需要撤销两个提交（每个分支一个）。
     - 记住 pushed 是远程分支，local 是本地分支 —— 这么说你应该知道用分别哪种方法了吧？

## 2.2 处理复杂问题
### 2.2.1 修改提交树
1. 自由修改提交树``git cherry-pick``
   - 清楚知道所需要提交的记录
   - 提交记录插入分支的指向
2. 交互式的``rebase``
   - 从一系列的提交记录中找到想要的记录
   - rebase --interactive(-i)
- 当 rebase UI界面打开时, 你能做3件事:

  - 调整提交记录的顺序（通过鼠标拖放来完成）
  - 删除你不想要的提交（通过切换 pick 的状态来完成，关闭就意味着你不想要这个提交记录）
  - 合并提交。 遗憾的是由于某种逻辑的原因，我们的课程不支持此功能，因此我不会详细介绍这个操作。简而言之，它允许你把多个提交记录合并成一个。
## 2.3 杂项
1. 本地自由栈式提交
   - 针对各个不同分支有一些调试或者打印的提交记录：复制解决问题的那几个提交就是（只提交一个分支）
   - 提交的技巧
     - 先用 ``git rebase -i`` 将提交重新排序，然后把我们想要修改的提交记录挪到最前
     - 然后用 ``commit --amend`` 来进行一些小修改
       - 会合并当前提交和上一次的提交，如果当前提交有注释，则以当前的注释为合并后的提交的注释，若当前提交没有注释，则以上一次提交的注释作为合并后的提交的注释
     - 接着再用 ``git rebase -i`` 来将他们调回原来的顺序
     - 最后我们把 ``master`` 移到修改的最前端（用你自己喜欢的方法），就大功告成啦！
2. 永远地指向某一个提交记录分支或者提供类似功能（标签）
   - 标签，对应关系：标签→锚点
     - ``git tag 标签 实际节点``
       - 主要区别就是：不会随着分支的移动而移动；
    - describe，用于描述最近的锚点
      - ``git describe <ref>``
        - 与``git bisect``（一个查找产生 Bug 的提交记录的指令）一起结合使用
        - 输出结果：``<tag>_<numCommits>_g<hash>``，tag是指的离ref最近的tag标签
3. 高级操作
    - 多次rebase
      - 把多个分支rebase到master，按照规定的顺序；
    - 选择父提交节点
      - 操作符 ^ 与 ~ 符一样，后面也可以跟一个数字。他们意义不同：
        - ^指定合并提交记录的某个父提交（针对有多个父节点的时候）,~就是返回多少代。``git branch bugWork master^^2^``
    - 纠缠不清的分支：多个分支都需要做不同的操作或者提交
      - 三个分支：one 需要重新排序并删除 C5，two 仅需要重排排序，而 three 只需要提交一次
# 3. 远程操作相关篇章
## 3.1 push && pull----git远程仓库
1. clone一个远程仓库
  - git clone
  - 本地多的远程分支：o/master（远程分支有一些特殊的属性）
    - 远程分支反映了远程仓库(在你上次和它通信时)的状态
    - 远程分支有一个特别的属性：检出时自动进入分离 HEAD 状态。所以做法是：（更新了远程分支之后）再用远程分享你的工作成果。
    - o代表远程仓库默认为origin
      - 远程仓库的命名规则：``<remote name>/<branch name>``
  - git fetch: 向远程仓库传输数据以及从远程仓库获取数据。
    - git fetch 通常通过互联网（使用 http:// 或 git:// 协议) 与远程仓库通信。
    - 会更新本地没有的记录而不会更新实际内容（这点尤其需要注意），以及将指针指向``o/master``
  - git pull：将变化的内容更新到本地
    - 等同于两个命令：
      - ``git fetch;git merge o/master``
      - ``git pull --rebase`` 就是 ``fetch`` 和 ``rebase`` 的简写！
  - 模拟团队协作：
    - 模拟提交：git fakeTeamwork foo 3
  - git push：与git pull相对，将本地上传到远程数据库
    - git push 负责将你的变更上传到指定的远程仓库；
    - git push 不带任何参数时的行为与 Git 的一个名为 push.default 的配置有关，使用的时候最好进行检查。
  - 偏离的提交记录
    - 具体原因造成：成员更改了API，你是基于原本的API进行开发
    - 通过rebase进行解决
      - ``git fetch;git rebase o/master;git push;``
    - 也可以使用merge，只要告诉git当前提交已经包含了远程分支的所有状况
      - ``git fetch;git merge o/master;git push;``
  - 远程服务器拒绝!(``Remote Rejected``)(锁定的Master(Locked Master))
    - 必须使用pull request来更新这个分支(在团队中合作可能会进行相关master锁定)
    - 相应流程：
      1. 新建一个分支；
      2. reset你的master分支和远程服务器保持一致；
         1. 重置操作：``git reset --hard o/master;``(这种是硬重置，一般默认是--mixed)
      3. 推送(push)这个分支并申请pull request；
    - 流程代码：
      1. ``git reset --hard o/master;``
      2. ``git checkout -b feature C2;``
      3. ``git push origin feature;``
## 3.2 关于 origin 和它的周边 —— Git 远程仓库高级操作
1. 推送主分支
   - 完成两个操作：
      1. 将特性分支集成到 master 上；
      2. 推送并更新远程分支；
   - 实现过程
      1. ``git fetch``
      2. ``git rebase o/master side1``
      3. ``git rebase side1 side2``
      4. ``git rebase side2 side3``
      5. ``git rebase side3 master``
      6. 快速前进。。。
      7. ``git push``
2. 合并远程仓库
   - rebase与merge之间的区别：  
     - 优点：Rebase 使你的提交树变得很干净, 所有的提交都在一条线上
     - 缺点：Rebase 使你的提交树变得很干净, 所有的提交都在一条线上
     - 喜欢保留提交历史，更偏爱 merge；喜欢干净的提交树，偏爱 rebase；因此使用什么根据自己习惯就行。
   - 实现过程：
      1. ``git checkout master;``
      2. ``git pull;``
      3. ``git merge side1;``
      4. ``git merge side2;``
      5. ``git merge side3;``
      6. ``git push;``
   - 过程图：
     ![合并之前的原图](https://upload-images.jianshu.io/upload_images/16953224-bff659ee81ac4be9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
    ![合并之后的结果图](https://upload-images.jianshu.io/upload_images/16953224-9d8320847d5dad51.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
3. 远程追踪
   - 本地分支与远程分支之间的关联（通过push以及pull）：
     1. pull：提交记录会被先下载到 o/master 上，之后再合并到本地的 master 分支
     2. push：把工作从 master 推到远程仓库中的 master 分支(同时会更新远程分支 o/master)
     3. 分支的``remote tracking``（远程跟踪）属性决定,并且``git clone``的时候就已经进行设定了,注意提示语句：local branch "master" set to `track remote branch` "o/master"
        1. 自己指定锁定属性：分支会像 master 分支一样得到隐含的 push 目的地以及 merge 的目标。
           - 可以在分支 totallyNotMaster 上执行 git push，将工作推送到远程仓库的 master 分支上
           - ``git checkout -b totallyNotMaster o/master``(第一种方法)检出一个分支跟踪o/masters
           - git branch -u o/master foo(当前就在 foo 分支上, 还可以省略 foo)
4. ``git push``的参数1
5. ``git push``的参数2
6. ``git fetch``的参数
7. 没有source的``source``
8. ``git pull``的参数$\sum_{r=1}^n$
  $$ \sum_{r=1}^n $$
  $$\sqrt {{a^2} + {b^2}} $$
    
