//
//  AsboloteCpp_ch11_5
//

#include <iostream>
using namespace std;

namespace Space1
{
    void greeting( );
}

namespace Space2
{
    void greeting( );
}

void bigGreeting( );

int main(int argc, const char * argv[]) {
    
    {
        using namespace Space2;
        greeting( );
    }
    
    {
        using namespace Space1;
        greeting( );
    }
    
    bigGreeting( );
    
    return 0;
}

namespace Space1
{
    void greeting( ){
        cout << "Hello from namespace Space1.\n";
    }
}

namespace Space2
{
    void greeting( ){
        cout << "Greetings from namespace Space2.\n";
        
    }
}

void bigGreeting( )
{
    cout << "A Big Global Hello!\n";
}
