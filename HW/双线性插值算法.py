def bilinear_interpolation(x, y, A, B, C, D):
    """
    Perform bilinear interpolation on a grid of four points.

    Parameters:
    x, y: Coordinates of the target point.
    A, B, C, D: Coordinates and gray levels of the four neighboring points.
               A: (x0, y0, g(A))
               B: (x1, y0, g(B))
               C: (x0, y1, g(C))
               D: (x1, y1, g(D))

    Returns:
    g: The gray level of the target point after bilinear interpolation.
    """
    # Extract coordinates and gray levels of the points
    x0, y0, g_A = A
    x1, y0, g_B = B
    x0, y1, g_C = C
    x1, y1, g_D = D
    
    # Perform bilinear interpolation
    # Interpolate first in the x-direction for points E and F
    g_E = (x - x0) / (x1 - x0) * (g_B - g_A) + g_A
    g_F = (x - x0) / (x1 - x0) * (g_D - g_C) + g_C
    
    # Interpolate in the y-direction to get final result g
    g = (y - y0) / (y1 - y0) * (g_F - g_E) + g_E
    
    return g

# Example points and their gray levels (x, y, gray level)
A = (0, 0, 10)   # Point A: (x0, y0, g(A))
B = (1, 0, 20)   # Point B: (x1, y0, g(B))
C = (0, 1, 30)   # Point C: (x0, y1, g(C))
D = (1, 1, 40)   # Point D: (x1, y1, g(D))

# Target point (x', y') where we want to find the gray level
x_target = 0.5  # x-coordinate of the target point
y_target = 0.5  # y-coordinate of the target point

# Calculate the gray level at the target point using bilinear interpolation
g_target = bilinear_interpolation(x_target, y_target, A, B, C, D)

# Output the result
print(f"目标点 ({x_target}, {y_target}) 的灰度值: {g_target}")
