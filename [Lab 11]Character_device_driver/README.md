* make all - 컴파일
  make clean - 현재 디록토리의 모든 object file들과 실행파일 제거

* character device 만드는 방법-> VM에서 아래 명령어를 실행해주세요.
mknod /dev/mycdev c 42 0
(= make character device with major:42 minor:0)

* labs/lab11 디렉토리에서 insmod my_cdev.ko
(= loading kernel module)

* cat /dev/mycdev
(= my_read 실행 테스트, 디폴트로는 hello 출력됩니다.)

* echo hi > /dev/mycdev
(= my_write, write hi 테스트, echo 로 입력한 문자열을 cat으로 출력할 수 있습니다.)


