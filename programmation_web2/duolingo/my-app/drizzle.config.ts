import "dotenv/config";
import type { Config } from "drizzle-kit";

const config: Config = {
    schema: "./db/schema.ts",  // Path to your schema file
    out: "./drizzle",          // Directory where migrations and other outputs will be stored
    dialect: "postgresql",             // PostgreSQL dialect
    dbCredentials: {
        host: process.env.DB_HOST!,
        port: Number(process.env.DB_PORT) || 5432,  // Default to 5432 if not provided
        user: process.env.DB_USER!,
        password: process.env.DB_PASSWORD!,
        database: process.env.DATABASE_URL!,
        ssl: process.env.DB_SSL === 'true' ? true : false, // Convert 'true'/'false' to boolean
    },
};

export default config;
