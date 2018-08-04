# X11, ssh
$ ffplay /tmp/output.mp4    # ssh连接时直接查看视频，会回传本地显示
$ feh /tmp/output.jpg       # ssh连接时直接查看图片，会回传本地显示
$ ffmpeg -i lane.mp4 frame-%04d.jpg                     # 视频转图片
$ ffmpeg -pattern_type glob -i "frame-*.jpg" video.mp4  # 图片转视频
# 同时播放两个视频（横着） 复杂 filtergraph 见 https://ffmpeg.org/ffmpeg-filters.html#Description
$ ffmpeg -i $1 -i $2 -filter_complex "[0:v]pad=iw*2:ih[bg]; [bg][1:v]overlay=w" /tmp/output.mp4
# 同时播放两个视频（竖着）
$ ffmpeg -i $1 -i $2 -filter_complex "[0:v]pad=iw:ih*2[bg]; [bg][1:v]overlay=0:h" /tmp/output.mp4
