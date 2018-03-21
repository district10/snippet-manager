// docker-compose.yml
//          app:
//              build: .
//              environment:
//                  REALM: prod
//                  REDIS_URL: "//redis:6379"
//              links:
//                  - redis
//              ports:
//                  - "8000:8000"
//
//          redis:
//              image: redis
docker-compose build
docker-compose up -d
