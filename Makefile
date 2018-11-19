.PHONY: clean how test_solve_puzzle c_path_planning parse_map

# Example to create new file
test_solve_puzzle: TARGET_MAIN_FILE = test_solve_puzzle.s
test_solve_puzzle: qtspimbot_run

c_path_planning: OUTPUT_EXE = c_path_planning
c_path_planning: SRC_FILES = C/pp_test.c C/path_planning.c C/make_map.c
c_path_planning: c_compile_and_run

parse_map: parse_map_run

# Rules to clean
clean:
	rm ./spimbot.s
	rm ./c_path_planning

# Rules to display helper
how:
	@echo "Example Usage: make test_solve_puzzle"
	@echo "This will assemble lib files along with main/test_solve_puzzle.s to form a file ready for submission"
	@echo "and perform a test run in QtSpimBot"

# Actual rule to make the targets
qtspimbot_run:
	python3 ./tool/assembler.py ${TARGET_MAIN_FILE}
	QtSpimbot -file spimbot.s -mapseed 233 -debug -prof_file profile.txt

parse_map_run:
	python3 ./tool/map_parser.py > ./C/make_map.c

c_compile_and_run:
	gcc -o ${OUTPUT_EXE} ${SRC_FILES}
	./${OUTPUT_EXE}
