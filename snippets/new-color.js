var new_color = (function() {
    // [网页设计的12种颜色 - 阮一峰的网络日志](http://www.ruanyifeng.com/blog/2010/09/12_colors_used_in_web_design.html)
    var colors = [
        "#8cc540", // 浅绿
        "#019fa0", // 暗蓝
        "#f8bd0b", // 黄色
        "#009f5d", // 深绿
        "#019fde", // 蓝色
        "#cd7bdd", // 浅紫
        "#ff8345", // 橙色
        "#007cdc", // 深蓝
        "#887ddd", // 深紫
        "#ff5675", // 粉色
        // "#d1d2d4", // 灰色
        // "#ff1244", // 红色
    ];
    var index = -1;
    return function() { return colors[++index % colors.length]; };
})();
