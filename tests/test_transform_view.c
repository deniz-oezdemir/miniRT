# include "../include/minirt.h"
# include "../include/tests.h"

/* t_vec3 point(double x, double y, double z) {
    return (t_vec3){x, y, z, 1.0};
}

t_vec3 vector(double x, double y, double z) {
    return (t_vec3){x, y, z, 0.0};
} */

bool matrices_are_equal(t_mtx a, t_mtx b) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (fabs(a.mtx[i][j] - b.mtx[i][j]) > 1e-6) {
                return false;
            }
        }
    }
    return true;
}

t_mtx identity_matrix() {
    t_mtx identity = {0};
    for (int i = 0; i < 4; i++) {
        identity.mtx[i][i] = 1.0;
    }
    return identity;
}

void test_transform_view(t_minirt *data)
{
    t_vec3 from = point(0, 0, 0);
    t_vec3 to = point(0, 0, -1);
    t_vec3 up = vector(0, 1, 0);
    
    t_mtx expected = identity_mtx(4);
    t_mtx actual = transform_view(from, to, up);
    
    printf ("\n*** Test transform view ***\n\n");

    if (matrices_are_equal(expected, actual)) {
        printf("Test passed!\n");
    } else {
        printf("Test failed!\n");
    }

    printf("\nIdentity matrix:\n");
	print_mtx(expected);
    printf("\n\nTransformed matrix:\n");
	print_mtx(actual);
}