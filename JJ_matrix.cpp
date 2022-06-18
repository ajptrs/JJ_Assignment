int main() {
    int test[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            test[i][j] = 0;
        }
    }

    test[1][2] = 1;
    std::cout << test << std::endl;
    //switcharoo();
}

void switcharoo() {
    int hello;
}