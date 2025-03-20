MLX=minilibx-linux/libmlx_Linux.a

INCLUDES_BONUS=-I bonus/includes
NAME_BONUS=miniRT_bonus
SRC_DIR_BONUS=bonus/src


INCLUDES=-I mandatory/includes
NAME=miniRT
SRC_DIR=mandatory/src


# ----------------------------------------------------------------------------------------------------------------------------
GC	=	$(SRC_DIR)/gc/gc.c

MAP	=	$(SRC_DIR)/map/reader.c \
		$(SRC_DIR)/map/getter.c \
		$(SRC_DIR)/map/writer.c \
		$(SRC_DIR)/map/writer_utils.c \
		$(SRC_DIR)/map/rendered_tools.c \
		$(SRC_DIR)/map/renderer.c \
		$(SRC_DIR)/map/interscet_cone.c \
		$(SRC_DIR)/map/intersect_cylinder.c \
		$(SRC_DIR)/map/intersections_others.c \
		$(SRC_DIR)/map/ray.c \
		$(SRC_DIR)/map/sphere.c \
		$(SRC_DIR)/map/plane.c \
		$(SRC_DIR)/map/cylinder.c \
		$(SRC_DIR)/map/cone.c \

MAP_POINTS = $(SRC_DIR)/map/points/utils1.c \
			$(SRC_DIR)/map/points/utils2.c \

SHADERS =	$(SRC_DIR)/shaders/index.c \
		 	$(SRC_DIR)/shaders/color.c \
		 	$(SRC_DIR)/shaders/shader.c \
			$(SRC_DIR)/shaders/lighting.c \

MAP += $(MAP_POINTS)

GUARDS = $(SRC_DIR)/guards/light.c	\
		$(SRC_DIR)/guards/camera.c	\
		$(SRC_DIR)/guards/sphere.c	\
		$(SRC_DIR)/guards/plane.c	\
		$(SRC_DIR)/guards/cylinder.c	\
		$(SRC_DIR)/guards/cone.c \
		$(SRC_DIR)/guards/utils.c	\
		$(SRC_DIR)/guards/point.c	\
		$(SRC_DIR)/guards/colors.c	\
		$(SRC_DIR)/guards/filter.c	\
		$(SRC_DIR)/guards/aa.c	\
		$(SRC_DIR)/guards/screen.c	\

MLX_SRC =	$(SRC_DIR)/mlx/init.c \
			$(SRC_DIR)/mlx/put.c \
			$(SRC_DIR)/mlx/colors.c \

EVENTS = $(SRC_DIR)/events/events.c \
		 $(SRC_DIR)/events/translate.c\
		 $(SRC_DIR)/events/selector.c\
		 $(SRC_DIR)/events/scalar.c\
		 $(SRC_DIR)/events/rotations_d.c\
		 $(SRC_DIR)/events/rotations.c\
		 $(SRC_DIR)/events/cam.c\
		 $(SRC_DIR)/events/any.c\
		 $(SRC_DIR)/events/selecter.c \

ERROR	=	$(SRC_DIR)/error/error.c

MAIN	=	$(SRC_DIR)/main.c\
			$(SRC_DIR)/engine.c \

CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
LDFLAGS = -lm -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g3 -fsanitize=address 

SRC = $(ACTIONS) $(GC) $(GUARDS) $(MAP) $(ERROR) $(MAIN) $(MLX_SRC) $(EVENTS) $(SHADERS)
OBJ = $(SRC:.c=.o)

LIBFT=mandatory/libft/libft.a
GNL=mandatory/get_next_line/get_next_line.o

# ----------------------------------------------------------------------------------------------------------------------------

# ---------------------------------------------------------------------------------------------------------------------------
GC_BONUS	=	$(SRC_DIR_BONUS)/gc/gc_bonus.c

MAP_BONUS	=	$(SRC_DIR_BONUS)/map/reader_bonus.c \
		$(SRC_DIR_BONUS)/map/getter_bonus.c \
		$(SRC_DIR_BONUS)/map/writer_bonus.c \
		$(SRC_DIR_BONUS)/map/writer_utils_bonus.c \
		$(SRC_DIR_BONUS)/map/rendered_tools_bonus.c \
		$(SRC_DIR_BONUS)/map/renderer_bonus.c \
		$(SRC_DIR_BONUS)/map/interscet_cone_bonus.c \
		$(SRC_DIR_BONUS)/map/intersect_cylinder_bonus.c \
		$(SRC_DIR_BONUS)/map/intersections_others_bonus.c \
		$(SRC_DIR_BONUS)/map/ray_bonus.c \
		$(SRC_DIR_BONUS)/map/sphere_bonus.c \
		$(SRC_DIR_BONUS)/map/plane_bonus.c \
		$(SRC_DIR_BONUS)/map/cylinder_bonus.c \
		$(SRC_DIR_BONUS)/map/cone_bonus.c \
		$(SRC_DIR_BONUS)/map/patterns_bonus.c \

MAP_POINTS_BONUS = $(SRC_DIR_BONUS)/map/points/utils1_bonus.c \
			$(SRC_DIR_BONUS)/map/points/utils2_bonus.c \

SHADERS_BONUS =	$(SRC_DIR_BONUS)/shaders/index_bonus.c \
		 	$(SRC_DIR_BONUS)/shaders/shader_bonus.c \
		 	$(SRC_DIR_BONUS)/shaders/lighting_bonus.c \

MAP_BONUS += $(MAP_POINTS_BONUS)

GUARDS_BONUS = $(SRC_DIR_BONUS)/guards/light_bonus.c	\
		$(SRC_DIR_BONUS)/guards/camera_bonus.c	\
		$(SRC_DIR_BONUS)/guards/sphere_bonus.c	\
		$(SRC_DIR_BONUS)/guards/plane_bonus.c	\
		$(SRC_DIR_BONUS)/guards/cylinder_bonus.c	\
		$(SRC_DIR_BONUS)/guards/cone_bonus.c \
		$(SRC_DIR_BONUS)/guards/utils_bonus.c	\
		$(SRC_DIR_BONUS)/guards/point_bonus.c	\
		$(SRC_DIR_BONUS)/guards/colors_bonus.c	\
		$(SRC_DIR_BONUS)/guards/filter_bonus.c	\
		$(SRC_DIR_BONUS)/guards/aa_bonus.c	\
		$(SRC_DIR_BONUS)/guards/screen_bonus.c	\

MLX_SRC_BONUS =	$(SRC_DIR_BONUS)/mlx/init_bonus.c \
			$(SRC_DIR_BONUS)/mlx/put_bonus.c \
			$(SRC_DIR_BONUS)/mlx/colors_bonus.c \

EVENTS_BONUS = $(SRC_DIR_BONUS)/events/events_bonus.c \
		 $(SRC_DIR_BONUS)/events/translate_bonus.c\
		 $(SRC_DIR_BONUS)/events/selector_bonus.c\
		 $(SRC_DIR_BONUS)/events/scalar_bonus.c\
		 $(SRC_DIR_BONUS)/events/rotations_d_bonus.c\
		 $(SRC_DIR_BONUS)/events/rotations_bonus.c\
		 $(SRC_DIR_BONUS)/events/cam_bonus.c\
		 $(SRC_DIR_BONUS)/events/any_bonus.c\
		 $(SRC_DIR_BONUS)/events/event_maper_bonus.c\

ERROR_BONUS	=	$(SRC_DIR_BONUS)/error/error_bonus.c

MAIN_BONUS	=	$(SRC_DIR_BONUS)/main_bonus.c \
			$(SRC_DIR_BONUS)/engine_bonus.c \
			$(SRC_DIR_BONUS)/threads_bonus.c \

CFLAGS_BONUS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -Ofast -pthread
LDFLAGS_BONUS = -lm -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz #-g3 -fsanitize=thread

SRC_BONUS = $(GC_BONUS) $(GUARDS_BONUS) $(MAP_BONUS) $(ERROR_BONUS) $(MAIN_BONUS) $(MLX_SRC_BONUS) $(SHADERS_BONUS) $(EVENTS_BONUS)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_BONUS=bonus/libft/libft.a
GNL_BONUS=bonus/get_next_line/get_next_line.o

# ----------------------------------------------------------------------------------------------------------------------------


all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT) $(GNL) $(MLX)
	@echo "Compiling miniRT..."
	@cc $(OBJ) $(GNL) $(LIBFT) $(MLX) -o $(NAME) $(LDFLAGS)
	@echo "miniRT coMLXmpiled successfully!"

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_BONUS) $(GNL_BONUS) $(MLX)
	@echo "Compiling miniRT..."
	@cc $(OBJ_BONUS) $(GNL_BONUS) $(LIBFT_BONUS) $(MLX) -o $(NAME_BONUS) $(LDFLAGS_BONUS)
	@echo "miniRT compiled successfully!"

mandatory/%.o: mandatory/%.c
	cc -c $< -o $@ $(INCLUDES) $(CFLAGS)

bonus/%.o: bonus/%.c
	cc -c $< -o $@ $(INCLUDES_BONUS) $(CFLAGS_BONUS)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C mandatory/libft

$(GNL):
	@echo "Compiling get_next_line..."
	@cc -c mandatory/get_next_line/get_next_line.c -o mandatory/get_next_line/get_next_line.o


$(LIBFT_BONUS):
	@echo "Compiling libft..."
	@make -C bonus/libft

$(GNL_BONUS):
	@echo "Compiling get_next_line..."
	cc -c bonus/get_next_line/get_next_line.c -o bonus/get_next_line/get_next_line.o

$(MLX):
	@echo "Compiling mlx..."
	@make re -C minilibx-linux

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ_BONUS) $(GNL_BONUS) $(OBJ) $(GNL)
	@make clean -C mandatory/libft
	@make clean -C bonus/libft
	@echo "Object files cleaned successfully!"

fclean: clean
	@echo "Cleaning miniRT..."
	@rm -f $(NAME_BONUS) $(NAME)
	@make fclean -C mandatory/libft
	@make fclean -C bonus/libft
	@rm -rf $(MLX)
	@echo "miniRT cleaned successfully!"

re: fclean all