module serial_adder(
    input [15:0] A,        // 加数A
    input [15:0] B,        // 加数B
    output reg [15:0] sum, // 和
    output reg carry_out    // 进位输出
);

    reg [15:0] temp_A;     // 临时存储A
    reg [15:0] temp_B;     // 临时存储B
    reg carry;             // 当前进位
    integer i;            // 迭代计数器

// always用于创建组合逻辑或时序逻辑
    always @(*) begin
        // 初始化
        sum = 16'b0;
        carry = 1'b0;

        // 位加法
        for (i = 0; i < 16; i = i + 1) begin
            {carry_out, sum[i]} = temp_A[i] + temp_B[i] + carry;
            carry = carry_out; // 更新进位
        end
    end

    // 在输入变化时更新临时A和B
    always @(*) begin
        temp_A = A;
        temp_B = B;
    end
endmodule