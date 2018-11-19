.PHONY: clean how test_solve_puzzle

# Example to create new file
test_solve_puzzle: TARGET_MAIN_FILE = test_solve_puzzle.s
test_solve_puzzle: qtspimbot_run

# Rules to clean
clean:
	rm spimbot.s

# Rules to display helper
how:
	@echo "Example Usage: make test_solve_puzzle"
	@echo "This will assemble lib files along with main/test_solve_puzzle.s to form a file ready for submission"
	@echo "and perform a test run in QtSpimBot"

# Actual rule to make the targets
qtspimbot_run:
	python3 ./tool/assembler.py ${TARGET_MAIN_FILE}
	QtSpimbot -file spimbot.s -mapseed 233 -debug -prof_file profile.txt
