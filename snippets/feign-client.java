@FeignClient(name = "server", url = "${feign.server.url:}")
public interface ServerClient {
    @RequestMapping(value = "/api/v1/...", method = GET, consumes = APPLICATION_JSON_VALUE)
    StatusDto getStatus(
            @RequestParam(value = "code") String code,
            @RequestParam(value = "reg", required = false) String reg
    );
}
