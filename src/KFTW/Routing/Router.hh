<?hh

namespace KFTW\Routing;

class Router {
    
    protected array<string, string> $routes;
    
    public function __construct() {
        $this->routes = [];
    }
    
    public function setRoutes(array<string, string> $routes) {
        $this->routes = $routes;
    }
    
    public function addRoutes(array<string, string> $routes) {
        foreach ($routes as $k => $v) {
            $this->addRoute($k, $v);
        }
    }
    
    public function addRoute(string $k, string $v) {
        $this->routes[$k] = $v;
    }
    
    public function getRoutes() : array<string, string> {
        return $this->routes;
    }
}