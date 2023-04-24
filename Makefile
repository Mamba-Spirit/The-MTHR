.PHONY: clean All

All:
	@echo "----------Building project:[ the_mthr_project - Debug ]----------"
	@cd "the_mthr_project" && "$(MAKE)" -f  "the_mthr_project.mk"
clean:
	@echo "----------Cleaning project:[ the_mthr_project - Debug ]----------"
	@cd "the_mthr_project" && "$(MAKE)" -f  "the_mthr_project.mk" clean
