module tb_spi_master;

    // Parameters
    parameter NUM_SLAVES = 4;
    parameter DATA_WIDTH = 8;

    // Testbench signals
    logic clk;
    logic rst_n;
    logic [DATA_WIDTH-1:0] tx_data;
    logic [$clog2(NUM_SLAVES)-1:0] slave_sel;
    logic start_transfer;
    logic cpol;
    logic cpha;
    logic [15:0] clk_div;

    logic [DATA_WIDTH-1:0] rx_data;
    logic transfer_done;
    logic busy;
    logic shift_pulse;
    logic sample_pulse;
    logic spi_clk;
    logic spi_mosi;
    logic spi_miso;
    logic [NUM_SLAVES-1:0] spi_cs_n;

    // Instantiate SPI Master
    spi_master #(
        .NUM_SLAVES(NUM_SLAVES),
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .tx_data(tx_data),
        .slave_sel(slave_sel),
        .start_transfer(start_transfer),
        .cpol(cpol),
        .cpha(cpha),
        .clk_div(clk_div),
        .rx_data(rx_data),
        .transfer_done(transfer_done),
        .busy(busy),
        .spi_clk(spi_clk),
        .spi_mosi(spi_mosi),
        .spi_miso(spi_miso),
        .spi_cs_n(spi_cs_n)
    );

    // Clock generation: 10ns period (100 MHz)
    initial clk = 0;
    always #5 clk = ~clk;

    // Test stimulus
    initial begin
        // Initialize
        rst_n = 0;
        tx_data = 8'hA5;
        slave_sel = 2;  // select slave 2
        start_transfer = 0;
        cpol = 1;
        cpha = 1;
        clk_div = 6;  // divide clock for SPI
        spi_miso = 0;

        #20;
        rst_n = 1;

        #20;
        // Start a transfer
        start_transfer = 1;
        #10;
        start_transfer = 0;

        // Simulate MISO from slave (example: send 0x3C back)
        repeat (8) begin
            @(posedge spi_clk);
            spi_miso <= $random % 2; // random bit for testing
        end

        // Wait until transfer_done
        wait (transfer_done == 1);
        $display("Transfer completed. RX data = %h", rx_data);

        #20;
        $finish;
    end

    // Monitor signals
    initial begin
        $monitor("Time=%0t clk=%b MOSI=%b MISO=%b RX=%h CS=%b busy=%b done=%b",
                 $time, spi_clk, spi_mosi, spi_miso, rx_data, spi_cs_n, busy, transfer_done);
    end

endmodule
