@RequestMapping(value = "/path/{vehicleProdId}", method = POST,
        headers = "key=value", consumes = APPLICATION_JSON_UTF8_VALUE)
DmsVehicleResponse syncVehicleToDms(@PathVariable(value = "vehicleProdId") long vehicleProdId,
                                    @RequestParam(value = "isSync") boolean isSync,
                                    @RequestHeader("X-REQUEST-TYPE") String requestType) { ... }
