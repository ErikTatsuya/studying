using Microsoft.AspNetCore.Mvc;

namespace Solar
{
    [ApiController]
    [Route("api/hello")]
    public class HelloController : ControllerBase
    {
        [HttpGet]
        public IActionResult SomeRandomAction()
        {
            return Ok("Por que têm tanto erro");   
        }
    }
}