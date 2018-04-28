@Value("#{'${file.allowed_type:xlsx,csv}'.replace(' ', '').split(',')}")
private Set<String> allowedTypes;

@PostMapping
@ResponseStatus(HttpStatus.ACCEPTED)
String uploadFile(@RequestParam("file") MultipartFile file) throws IOException {
    if (!allowedTypes.contains(FilenameUtils.getExtension(file.getOriginalFilename()))) {
        throw new IllegalFileTypeException();
    }
    try (InputStream inputStream = file.getInputStream()) {
        File outputFile = new File(file.getOriginalFilename());
        Files.copy(inputStream, outputFile.toPath(), StandardCopyOption.REPLACE_EXISTING);
        return outputFile.getCanonicalPath();
    }
}
