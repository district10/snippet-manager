<script src="res/toastr.min.js"></script>
<link href="res/toastr.min.css" rel="stylesheet" />

// toast message
toastr.options.positionClass = "toast-bottom-left";
toastr.success(msg, {timeOut: 10000});
toastr.info(msg);
toastr.warning(msg);
toastr.error(msg);
