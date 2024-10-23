// 在 Verilog 中，括号用于定义模块的输入和输出端口。
// 每个端口都有其类型（input、output）和数据类型（如 wire 或 reg）
module full_adder (
    input wire a,       // 输入位 a
    input wire b,       // 输入位 b
    input wire cin,     // 输入的进位 cin
    output wire sum,    // 输出的和 sum
    output wire cout    // 输出的进位 cout
);

// assign 语句用于将值赋给一个 wire 类型的变量
    // 计算和和进位
    assign sum = a ^ b ^ cin;       // 和
    assign cout = (a & b) | (cin & (a ^ b)); // 进位

endmodule