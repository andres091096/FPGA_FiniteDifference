################################################################################
##
## Filename: Makefile
##
## Project: Veilog tutorial - top
##
## Creator: Andrés Manjarrés
################################################################################
VINC = /usr/share/verilator/include
RTL_DIR := ./rtl

VFLAGS  := -Wall --trace -y $(RTL_DIR) -cc

.PHONY: all obj_dir/Vtop.cpp obj_dir/Vtop__ALL.a topDivergence test_div obj_dir/VtopDivergence.cpp obj_dir/VtopDivergence__ALL.a

test_div: topDivergence
	./topDivergence

obj_dir/VtopDivergence.cpp: $(RTL_DIR)/topDivergence.v
	verilator $(VFLAGS) $^

obj_dir/VtopDivergence__ALL.a: obj_dir/VtopDivergence.cpp
	make -C obj_dir -f VtopDivergence.mk

topDivergence: bench/topDivergence_tb.cpp obj_dir/VtopDivergence__ALL.a
	@echo "Building a Verilator-based simulation of top"

	g++ -I$(VINC)  -I obj_dir     \
		$(VINC)/verilated.cpp \
		$(VINC)/verilated_vcd_c.cpp \
		bench/topDivergence_tb.cpp  obj_dir/VtopDivergence__ALL.a     \
		-o topDivergence

all: top
	./top

obj_dir/Vtop.cpp: $(RTL_DIR)/top.v
	verilator $(VFLAGS) $^

obj_dir/Vtop__ALL.a: obj_dir/Vtop.cpp
	make -C obj_dir -f Vtop.mk

# Build a simulation
top: bench/top_tb.cpp obj_dir/Vtop__ALL.a
	@echo "Building a Verilator-based simulation of top"

	g++ -I$(VINC)  -I obj_dir     \
		$(VINC)/verilated.cpp \
		$(VINC)/verilated_vcd_c.cpp \
		bench/top_tb.cpp obj_dir/Vtop__ALL.a      \
		-o top

.PHONY: clean

clean:
	rm -rf obj_dir/
	rm -rf top
	rm -rf topDivergence
