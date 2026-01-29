using Microsoft.AspNetCore.Builder;
using Microsoft.Extensions.DependencyInjection;

var builder = WebApplication.CreateBuilder(args);

// Registrar controllers ANTES de Build
builder.Services.AddControllers();

var app = builder.Build();

// Mapear os controllers
app.MapControllers();

app.Run();
