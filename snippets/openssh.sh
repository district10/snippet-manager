# 安装 openssh
sudo apt-get install openssh-server
# 修改配置，允许自己登陆
sudo vi /etc/ssh/sshd_config # AllowUsers tzx

# 添加自己的公钥 cat ~/.ssh/id_rsa.pub >> ~/.ssh/authorized_keys，如果没有的话先用 ssh_keygen 生成密钥
# 确保自己的 pub 可以已经存入：
#       cat ~/.ssh/authorized_keys
#           ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDMLl/0cXodcoZFe+JLMN0Tb46DA5AKMAdGCPmOdDZfaJdTB/2OLNFHDdlzrqcnvP7L+Wg5+AGVabvzN3/bjcqCsACMPN6caT/HGeiS7c0Tx44AV3u15OZgy7tXCB8gmmr5PbANpcYrL4WBAmtBmBaer22It6lSGIiWy53cye8KX9sTLw8449KtCS95kiez6kfblBPA6bF9yPYykdInLw9pJAuPwk/AZDVOPAy68exVyV5D4+yb01OZqjGPrabp+Aq3NMbxgvaMZK1jyJE96WGjdr3ZY/Rr7NHp0sSCIqfMsy9wLQFvoQRhd8WpGwOQeByfmXmbYtd0mvAaIX1xiWkf dvorak4tzx@qq.com

# 重启
sudo service ssh restart

# 如果你没有对外的稳定 ip，可以用端口穿透实现电脑互联，参考：
#   [通过一台可公网访问的服务器链接两台电脑 - 简书](https://www.jianshu.com/p/423c491635fc)
nohup ssh -NR 2222:localhost:22 jap
