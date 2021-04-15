FROM alpine
RUN apk update && apk add nasm gcc g++ musl-dev
COPY main.cpp .
RUN g++ main.cpp -masm=intel -o main_cpp.out
CMD ./main_cpp.out
