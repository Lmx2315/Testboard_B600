
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name testboard -dir "C:/Work/Project_Testboard/Xilinx_project/testboard/planAhead_run_1" -part xc3s500epq208-4
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "C:/Work/Project_Testboard/Xilinx_project/testboard/top_modul.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {C:/Work/Project_Testboard/Xilinx_project/testboard} }
set_property target_constrs_file "list1.ucf" [current_fileset -constrset]
add_files [list {list1.ucf}] -fileset [get_property constrset [current_run]]
link_design
