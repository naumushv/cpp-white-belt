#include <iostream>
#include <exception>
#include <string>
#include <system_error>
using namespace std;

string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
	int cas = 0;
	if (cas == 0){
		return "01:12:11";
	}
	else if (cas == 1){
		return "94/23/34";
	}
	else if (cas == 2){
		throw system_error(error_code());
	}
	else if (cas == 3){
		throw runtime_error("runtime error message");
	}
	else return "02:34:23";

}

class TimeServer {
public:
    string GetCurrentTime() {
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
            *
            *
            if (!req.empty()){
    	    	    	    		last_fetched_time = req;
    	    	    				return last_fetched_time;
    	}
        */
    	try{
    	string req = AskTimeServer();
    	if (!req.empty()){
    	    	    	    	    		last_fetched_time = req;
    	    	    	    				return last_fetched_time;
		}

    	}
    	catch (system_error& ss) {
    		return last_fetched_time;
    	}
    	catch (runtime_error& rr){
    		throw;
    	}
    	catch (exception& rr){
    		throw;
		}

    }


private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    //Вам дан файл, содержащий заготовку класса TimeServer. В нём вам надо реализовать метод GetCurrentTime так, как описано выше. Файл содержит пустую функцию AskTimeServer. Для тестирования своей реализации вы можете пробовать добавлять разные команды в её тело:


    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
