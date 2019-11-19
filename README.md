# CTDL-GT
## Đồ Án môn Cấu trúc dữ liệu và giải thuật
18120598 - Huỳnh Gia Toại

18120618 - Hồ Hiếu Trọng

## Những câu đã làm được
1.	Tìm định thức ma trận
2.	Tìm hạng ma trận
3.	Tích hai ma trận
4.	Nghịch đảo ma trận
5.	Hệ phương trình tuyến tính
6.	Phép toán cộng hai vector
7.	Phép toán nhân vector với một số alpha
## Những câu chưa làm được:
1.	Tìm tất cả các công thức đa thức tối tiểu của hàm bool
## Công việc của từng thành viên:
### Huỳnh Gia Toại
1.	Giao diện chương trình: Gồm hàm in chữ trong một khung viền cho sẵn và căn giữa chữ in ra. Sử dùng do… while and switch…case để tạo các danh mục chọn cho chương trình
2.	Các hàm nhập và xuất ma trận: Gồm các vòng lặp for đơn giản duyệt tất cả các phần tử của mảng 2 chiều để nhập hoặc in ra ma trận.
3.	Tìm định thức ma trận: Hàm tính định thức ma trận đệ quy nhận một ma trận vuông với NxN với điều kiện dừng là khi gặp ma trận 1x1, trả về phần tử duy nhất trong ma trận hoặc khi gặp ma trận 2x2, trả về định thức ma trận 2x2 đơn giản a*d-b*c. Hàm hoạt động bằng cách tạo ra một ma trận con tạm thời tương ứng với mỗi phần tử trên dòng đầu tiên của ma trận. Ma trận con sẽ chứa các phần tử không nằm trên dòng và cột của các phần tử được chọn trên dòng đầu tiên. Sau đó sẽ thực hiện tính toán luân phiên cộng trừ định thức bằng cách thay đổi biến “phepToan” mỗi lần thực hiện, nhân với phần tử dòng đầu tiên của ma trận, và nhân với định thức đệ quy của ma trận con ứng với phần tử dòng đầu tiên.
4.	Tìm hạng ma trận: Đặt số hạng mặc định của ma trận là min của dòng và cột, sau đó thực hiện các thao tác rút gọn ma trận về dạng bậc thang, đếm các dòng trống chỉ gồm các số 0 và trừ dần số hạng của ma trận với mỗi dòng trống đếm được.
### Hồ Hiếu Trọng
1.	Tích hai ma trận: Hàm tính tích hai ma trận sử dụng hai vòng lặp for chạy hết các phần tử trong ma trận phụ, bên trong, chạy thêm một vòng lặp for và thực hiện phép tính dòng*cột+dòng*cột+…. để ra tích hai ma trận.
2.	Nghịch đảo ma trận: Tạo một ma trận với n dòng và 2n cột. N cột đầu tiên lưu giá trị của ma trận nhập vào, n cột sau để lưu giá trị của ma trận nghịch đảo cần tính. Tính từng phần tử bằng cách chạy dòng lặp và thao tác theo từng phần tử trên đường chéo, chia từng phần tử cùng dòng cho phần tử trên đường chéo, tiếp tục vòng lặp bên trong bằng cách lấy các phần tử trong ma trận trừ tỉ lệ từng phần tử theo dòng.
3.	Hệ phương trình tuyến tính: Rút gọn ma trận về dạng ma trận bậc thang( ma trận tam giác trên) sau đó thực hiện các phép rút thế để tìm các giá trị của x.
4.	Phép toán cộng hai vector: phần tử thứ I của vectơ tổng bằng tổng hai phần tử thứ I của hai vectơ thành phần.
5.	Phép toán nhân vector với một số alpha: Là nhân từng phần tử của vectơ lần lượt cho một số alpha.
## Video
https://drive.google.com/open?id=1c0cCPMcnfTIyUq9_QLVm87qh-Z0uN4ia
