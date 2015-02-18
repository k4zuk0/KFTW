<?hh

namespace KFTW\Bundle;

class Bundle {
    
    protected array<string, array<string>> $routes;
    
    public function __construct() {
        $this->routes = [];
    }
    
    public function getRoutes() : array<string, array<string>> {
        return $this->routes;
    }
    
    public function setRoutes(array<string, array<string>> $routes) {
        $this->routes = $routes;
    }
}